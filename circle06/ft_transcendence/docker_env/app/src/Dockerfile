# Node.js 이미지를 사용
FROM node:16

# 작업 디렉토리 생성
WORKDIR /app

# nvm 설치
RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash

# nvm 활성화
RUN . ~/.nvm/nvm.sh && \
    nvm install --lts

# 앱 종속성 설치
COPY package*.json ./
RUN . ~/.nvm/nvm.sh && \
    npm install

# React 앱 소스 복사
COPY ./src ./src

# React 앱 설치
RUN . ~/.nvm/nvm.sh && \
    npx create-react-app my-app

# 앱 디렉토리로 이동
WORKDIR /app/my-app

CMD [ "npm", "start" ]
