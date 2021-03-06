#ifndef BADA_THREAD_H_
#define BADA_THREAD_H_

#include "worker_thread.h"
#include "pink.pb.h"
#include "pb_conn.h"
#include <google/protobuf/message.h>

#include <string>

using namespace pink;

class BadaThread;

class BadaConn: public PbConn {
public:
  BadaConn(int fd, std::string ip_port, Thread *thread);
  virtual ~BadaConn();
  virtual int DealMessage();

private:
  pink::Ping ping_;
  pink::PingRes pingRes_;

  BadaThread *bada_thread_;
};


class BadaThread : public WorkerThread<BadaConn>
{
public:
  BadaThread(int cron_interval = 0);
  virtual ~BadaThread();

  int PrintNum();

private:

  int bada_num_;

};

#endif
