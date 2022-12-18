#pragma once

#include <QSyntaxHighlighter>
#include <QTextDocument>

class MarkdownTextEdit;

class MarkdownHighlighter : public QSyntaxHighlighter
{
public:
  MarkdownHighlighter(MarkdownTextEdit* editor);

protected:
private:
  MarkdownTextEdit *m_editor;
};

