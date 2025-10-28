FROM ubuntu:24.04

COPY --chown=ubuntu:ubuntu conf/session.json /home/ubuntu/.config/atcoder-cli-nodejs/
COPY --chown=ubuntu:ubuntu conf/cookie.jar /home/ubuntu/.local/share/online-judge-tools/
COPY <<EOF /etc/sudoers.d/ubuntu
ubuntu ALL=(ALL) NOPASSWD:ALL

EOF

RUN <<EOF
apt-get update
apt-get install -y tzdata
ln -fs /usr/share/zoneinfo/Asia/Tokyo /etc/localtime
EOF

RUN <<EOF
apt-get install -y sudo g++ pipx npm gdb xclip
npm install -g atcoder-cli
EOF

USER ubuntu
RUN <<EOF
pipx install online-judge-verify-helper online-judge-tools
pipx inject online-judge-tools setuptools
EOF
ENV PATH=/home/ubuntu/.local/bin:$PATH
