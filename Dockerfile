# our local base image
FROM ubuntu 

LABEL description="Container for use with Visual Studio" 

# install build dependencies 
RUN apt-get update && apt-get install -y g++ rsync zip openssh-server make

# Install the Clang compiler
RUN apt-get -y install clang

# configure SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd

RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A

RUN echo 'service ssh start'
RUN echo 'useradd -m -d /home/seandeeze -s /bin/bash -G sudo seandeeze'
RUN echo 'passwd seandeeze'
RUN echo 'mypassword'
RUN echo 'mypassword'


# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/src/linkedlist

# Specify the working directory
WORKDIR /usr/src/linkedlist/LinkedLinked/LinkedList

RUN g++ LinkedList.cpp

RUN ./a.out

# expose port 22 
EXPOSE 22