FROM ubuntu

RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y libelf-dev gcc-avr avr-libc
RUN apt-get install -y socat
