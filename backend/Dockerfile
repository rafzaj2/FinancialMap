FROM financialmaporg/backend:latest

RUN apt-get update \
  && apt-get install -y \
     build-essential \
     software-properties-common \
     wget

RUN apt-get install -y \
     git \
     curl \
     vim \
     make \
     gcc-7 \
     g++-7 \
     automake \
     autoconf \
     autoconf-archive \
     libtool \
     libssl-dev \
	 lcov \
	 cmake && \
     apt-get clean \
     libgflags-dev \
     liblz4-dev \
    && rm -rf /var/lib/apt/lists/*

ENV LD_LIBRARY_PATH=/libs
ENV CPLUS_INCLUDE_PATH=/libs/include
ENV CC=/usr/bin/gcc-7
ENV CXX=/usr/bin/g++-7

WORKDIR /app

# Make port 80 available to the world outside this container
EXPOSE 80

CMD ["/bin/bash"]
