#include "SMLibraries/widgets/markdownhighlighter.h"
#include "SMLibraries/widgets/markdowntextedit.h"

MarkdownHighlighter::MarkdownHighlighter(MarkdownTextEdit* editor)
  : QSyntaxHighlighter(editor->document())
  , m_editor(editor)
{
}
