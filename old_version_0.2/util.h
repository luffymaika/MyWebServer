#ifndef UTIL
#define UTIL
#include <cstdlib>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

ssize_t readn(int fd, void *buff, size_t n);
ssize_t writen(int fd, void *buff, size_t n);
void handle_for_sigpipe();
int setSocketNonBlocking(int fd);

namespace luffy {

class nocopyable {
public:
    nocopyable() = default;
    nocopyable(const nocopyable&) = delete;
    nocopyable(nocopyable&&) = delete;
    nocopyable& operator=(const nocopyable&) = delete;
    nocopyable& operator= (nocopyable&&) = delete;

private:
    // ~nocopyable() = default;
};

pid_t gettid() {
    return static_cast<pid_t>(::syscall(SYS_gettid));
};

}

#endif