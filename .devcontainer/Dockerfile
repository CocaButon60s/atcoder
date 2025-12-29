FROM ubuntu:24.04

ARG REVEL_SESSION

COPY <<EOF /etc/sudoers.d/ubuntu
ubuntu ALL=(ALL) NOPASSWD:ALL

EOF

RUN <<EOF
apt-get update
apt-get install -y tzdata
ln -fs /usr/share/zoneinfo/Asia/Tokyo /etc/localtime
EOF

RUN <<EOF
apt-get install -y sudo g++ pipx npm gdb xclip time
npm install -g atcoder-cli
EOF

USER ubuntu

COPY --chown=ubuntu:ubuntu <<EOF /home/ubuntu/.config/atcoder-cli-nodejs/session.json
{
  "cookies": [
    "REVEL_FLASH=",
    "REVEL_SESSION=${REVEL_SESSION}"
  ]
}

EOF
COPY --chown=ubuntu:ubuntu <<EOF /home/ubuntu/.local/share/online-judge-tools/cookie.json
#LWP-Cookies-2.0
Set-Cookie3: REVEL_FLASH=""; path="/"; domain="atcoder.jp"; path_spec; secure; discard; HttpOnly=None; version=0
Set-Cookie3: REVEL_SESSION="${REVEL_SESSION}"; path="/"; domain="atcoder.jp"; path_spec; secure; expires="2026-06-26 19:06:01Z"; HttpOnly=None; version=0

EOF

RUN <<EOF
pipx install online-judge-verify-helper online-judge-tools
pipx inject online-judge-tools setuptools
EOF
ENV PATH=/home/ubuntu/.local/bin:$PATH
