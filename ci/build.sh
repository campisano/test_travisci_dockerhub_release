#!/bin/bash

apt-get -q update
apt-get -q -y install git gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev
make -e release