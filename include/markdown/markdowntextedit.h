#pragma once

#include "SMLibraries/widgets/lnplaintextedit.h"

class MarkdownTextEdit : public LNPlainTextEdit
{
  Q_OBJECT
public:
  MarkdownTextEdit(QWidget* parent);

  bool isModified() const override;

  void setKeyMap(const QMap<KeyEvent, KeyMapper> &keyMap);

  //! Returns the file name loaded via loadHref(const QString&)
  const QString filename() const;
  //! loads the file in href into the editor.
  void loadFile(const QString& filename);
  //! Loads the file in href from the zipped file zipfile.
  void loadFromZip(const QString &zipFile, const QString& href);
  //! Loads plain text into the editor
  void setText(const QString& text);

protected:
private:
  bool m_modified = false;
  QMap<KeyEvent, KeyMapper> m_keyMap;
  QString m_filename;
  QString m_zipFile;

  void textHasChanged(int position, int charsRemoved, int charsAdded);

};
