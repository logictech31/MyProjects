1. main() -> Starts the execution of the daemon
   
2. getopt(argc, argv, "htTC[#if COLLECTD_DAEMON]fP[#endif]") -> Get the command line arguments passed to argv
   
3. exit_usage() -> With code 0, it will only print how to use the program. With code 1, it will return error and show the help symbol. The first one is done when -h is passed and the latter if the argument passed is invalid.
   
4. plugin_init_ctx(void) -> Creates a plugin context by called pthread_key_create() to create a key. It also sets the global static variable `plugin_key_initialized = 1`
   
5. pthread_key_create(pthread_key_t, void \*(destructor_function)(void \*)): This function will initialize the key pointer and allocate a TSD area i.e. Thread-Specific Data area.
   
6. cf_read(configFile): Is responsible for reading and validating the config file that is being used by the user.
   
7. dispatch_value(oconfig_item_t \*ci): 
8. dispath_global_option(const oconfig_item_t \*t):
   
7. cf_read_generic_name(const char \*path, const char \* pattern, int depth): This function is responsible for collecting status to to the path of the config file.
   
8. global_option_get(const char \* option): For each option that exists, which are: *BaseDir, PIDFile, Hostname, FQDNLookup, Interval, ReadThreads, WriteThreads, WriteQueueLimitHigh, WriteQueueLimitLow, Timeout, AutoLoadPlugin, CollectInternalStats, PreCacheChain, PostCacheChain, MaxReadInterval*
9. start_read_threads(size_t num)
10. start_write_threads(size_t num)