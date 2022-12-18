#include "markdownedit/markdowntextedit.h"

#include <JlCompress.h>

MarkdownTextEdit::MarkdownTextEdit(QWidget *parent) : LNPlainTextEdit(parent)
{

}

bool MarkdownTextEdit::isModified() const { return m_modified; }

void MarkdownTextEdit::setKeyMap(const QMap<KeyEvent, KeyMapper> &keyMap)
{
  m_keyMap = keyMap;
}

const QString MarkdownTextEdit::filename() const
{
  return m_filename;
}

void MarkdownTextEdit::loadFile(const QString &filename)
{
  m_filename = filename;
  QFile file(m_filename);
  if (file.open(QIODevice::ReadOnly)) {
    auto text = file.readAll();
    setText(text);
  }
}

void MarkdownTextEdit::loadFromZip(const QString &zipFile, const QString &href)
{
  m_filename = href;
  m_zipFile = zipFile;
  auto fileName = JlCompress::extractFile(zipFile, href);
  QFile file(fileName);
  if (file.open(QIODevice::ReadOnly)) {
    auto text = file.readAll();
    setText(text);
  }
}

void MarkdownTextEdit::setText(const QString &text)
{
  disconnect(LNPlainTextEdit::document(),
             &QTextDocument::contentsChange,
             this,
             &MarkdownTextEdit::textHasChanged);
  QPlainTextEdit::setPlainText(text);
  // TODO
//  m_scanner->load(text);
//  auto cursor = textCursor();
//  auto tag = m_scanner->tagAt(cursor.position());
//  m_highlighter->setCurrentTag(tag);
//  m_highlighter->rehighlight();
  connect(LNPlainTextEdit::document(),
          &QTextDocument::contentsChange,
          this,
          &MarkdownTextEdit::textHasChanged);

}

void MarkdownTextEdit::textHasChanged(int position, int charsRemoved, int charsAdded)
{
  // TODO
}
