#!/bin/bash

prefix="${0%${0##*/}}"

mkdir -p "${prefix}linux"
cd "${prefix}linux"

cmake ../..

