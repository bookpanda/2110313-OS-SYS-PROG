```bash
gcc 1.c -lpthread
ps m -o pid,tid,command
```

## What pthread_join Does
- pthread_join blocks the calling thread (typically the main thread) and waits for a specific thread to complete before continuing.
- However, it doesn't prevent other threads from executing. If you call pthread_create to start multiple threads and only pthread_join after all the threads are created, all the threads will still run concurrently.