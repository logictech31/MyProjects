Collectd has a few components that are compiled after running make command, the execs that are made are:
collectd
collectdmon
collectd-nagios
collectd-tg
collectdctl

Descriptions:
collectd: This is the system statistics daemon that receives the system statistics from defined resources through number of ways. The main daemon only performs loading, querying, and submitting to plugins.
The main source of gathering this information is through a "Plugin"
```mermaid
graph TD;
%% Start
id1(main)
id1.1(c = getopt_argc_argv)
id1.1.1(Argument 'C' will assign config file as the one passed at optarg)
id1.1.2(Argument 't' will set test_config=1)
id1.1.3(Argument 'T' will set test_read_all=1)
id1.1.4(For COLLECTD_DAEMON macro daemonize=0)
id1.1.5(Argument 'P' will set a global option for PID FILE)
id1.1.6(Argument 'f' will set daemonize=0)
id1.1.7(Argument 'h' will display help It will also be display if incorrect argument passed)
id1.9(plugin_init_ctx to initialize pthread_key)

%% Initialization of Plugins
id2.1(Reading the config file)
id2.2(Check if the config file == NULL)
id2.3(Dispatch the value in the config file)
id2.4(notify_upstart && notify_systemd)
id2.5(Fork the child process and call setsid to start a new process itself)
id2.6(do_init)
id2.7(plugin_init_all)

id99(ABNORMAL_EXIT)

%% ---- Links ----
id1 --> id1.1
id1.1 -- IF NO ARGUMENTS PASSED --> id1.9
id1.1 --> id1.1.1
id1.1 --> id1.1.2
id1.1 --> id1.1.3
id1.1 --> id1.1.4
id1.1 --> id1.1.5
id1.1 --> id1.1.6
id1.1 --> id1.1.7
id1.1.1 --> id1.9
id1.1.2 --> id1.9
id1.1.3 --> id1.9
id1.1.4 --> id1.9
id1.1.5 --> id1.9
id1.1.6 --> id1.9
id1.1.7 --> id1.9
```

Important functions:
pthread_key_create: This is needed to manage the different static variables and the different global variables that belong to N threads. pthread_key_create allocates a new TSD key which helps access TSD (Thread Specific Data) area which is Private area of thread.
void * are assosciated to TSD Keys.

plugin_init_all: Will initialize plugins and start reader#N and writer#N threads


collectdmon: 
This is the monitoring daemon for collectd. It acts as a small wrapper daemon which starts and monitors the collectd daemon. If collectd terminates it will be automatically restarted unless collectdmon was told to shut it down.

collectd-nagios:
Nagios plugin for querying with collectd. (Need to see working and uses)

collectd-tg:
This is the traffic generator of collectd which generates bogus traffic. It mimics real traffic as much as it can.

collectdctl:
This is the control interface of collectd that provides control interface for collectd, which may be used to interact with the daemon itself. This is done through the "unixsock plugin".




