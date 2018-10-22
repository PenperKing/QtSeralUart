#include "utils.h"
#include <QDebug>


void show_char(QByteArray& buf, QTextEdit* textEdit)
{
  QString bufOut;
  for (int i = 0; i < buf.length(); i++) {
    qDebug() << QByteArray::number(buf[i], 16) << endl;

    bufOut.append(QByteArray::number(buf[i], 16) + " ");
  }

  if(!buf.isEmpty())
  {
    QString str = textEdit->toPlainText();
    str += bufOut;
    textEdit->clear();  // 清楚接收缓冲
    textEdit->append(str);
  }
  buf.clear();
}
