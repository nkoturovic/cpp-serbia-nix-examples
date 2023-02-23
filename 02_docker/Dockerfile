FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y g++ cmake libspdlog-dev libsdl2-dev libsdl2-ttf-dev

COPY . /hello-cpp-serbia
WORKDIR /hello-cpp-serbia

RUN mkdir build
WORKDIR /hello-cpp-serbia/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release
RUN make

CMD [ "./hello_cpp_serbia" ]
