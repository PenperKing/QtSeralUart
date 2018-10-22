#include "utils.h"
#include <QDebug>


void show_char(QByteArray& buf,
               QTextEdit* textEdit,
               bool auto_return_feeds)
{
  QString bufOut;
  for (int i = 0; i < buf.length(); i++) {
    qDebug() << QByteArray::number(buf[i], 10) << endl;
    if (auto_return_feeds && (buf[i] == 13 || buf[i] == 10)) {
      if (buf[i] == 13 && i != buf.length() && buf[i+1] == 10)
        bufOut += "\n";
    } else {
      bufOut.append(QByteArray::number(buf[i], 16) + " ");
    }
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
