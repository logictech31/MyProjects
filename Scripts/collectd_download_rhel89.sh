#!/bin/bash
if [ $USER == "root" ]
then
    wget https://storage.googleapis.com/collectd-tarballs/collectd-5.12.0.tar.bz2
    tar xf collectd-5.12.0.tar.bz2
    cd collectd-5.12.0/
    ./configure
    make all install
    echo "COLLECTD_DIR=\"/root/collectd-5.12.0\"" | tee -a /root/.bashrc
    echo "export PATH=\"$PATH:$COLLECTD_DIR/bin\"" | tee -a /root/.bashrc
else
    echo "Run this as root user."
fi