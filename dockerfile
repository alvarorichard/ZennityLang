# Use Alpine Linux as the base image
FROM alpine:latest

# Install build dependencies
RUN apk add --no-cache \
    gcc \
    clang \
    libc-dev \
    make \
    git \
    # Install libedit-dev for editline/readline and editline/history
    libedit-dev

# Clone the libedit repository (if required)
# RUN git clone https://github.com/thrysoee/libedit.git
# RUN cd libedit && ./configure && make && make install

# Set the working directory
WORKDIR /workspace

# Copy your C source code into the Docker image
COPY . /workspace

# Compile the code (replace `your_program.c` with the actual file name)
# You can switch between gcc and clang by changing the compiler command
RUN gcc -o your_program your_program.c -ledit -lm
# Or using Clang:
# RUN clang -o your_program your_program.c -ledit -lm

# Command to run when the container starts
