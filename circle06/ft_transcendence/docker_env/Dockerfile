# 기반 이미지 설정
FROM ubuntu:latest

# 환경 변수 설정
ENV DEBIAN_FRONTEND=noninteractive

# 필요한 패키지 설치
RUN apt-get update && apt-get install -y \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

# NVM 설치
RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.38.0/install.sh | bash

# NVM 활성화
RUN export NVM_DIR="$HOME/.nvm" \
    && [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm

# Node.js 및 React 설치
RUN nvm install --lts
RUN npm install -g create-react-app

# 작업 디렉토리 설정
WORKDIR /app

# 컨테이너 실행 시 실행할 명령 설정
CMD ["npm", "start"]