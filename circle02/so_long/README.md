# So long

## -And thanks for all the fish!-
> 작은 2D 게임을 만들자.

## 1. 프로젝트 소개
-----
이번 프로젝트는 매우 작은 규모의 2D 게임을 제작하는 것이다. 제공되는 라이브러리인 miniLibX를 통해 간단한 텍스쳐, 스프라이트, 방향키 조작을 다뤄보자.

## 2. 프로젝트 공용 규칙
-----
+ 프로젝트는 C로 작성되어야 한다.
+ *.c 파일과 *.h 파일은 norminette 규칙에 맞게 작성되어야 한다.
+ 함수는 정의되지 않은 행동과 별개로 예기치 않게 중단되어서 안 된다. segmentation fault, bus error, double free 등등을 일으키면 안 된다.
+ 메모리 누수는 일어나면 안 된다.
+ Makefile을 작성해야 하며 CC로 ```-Wall -Wxtra -Werror``` 플래그를 지정하여 컴파일 되어야 한다. Makefile은 relink 되어서는 안 된다.
  
위 규칙은 42seoul 프로젝트를 진행하는 동안, 대부분의 경우에 적용되는 규칙이다.

## 3. 프로젝트 세부 규칙
-----
+ 반드시 miniLibX를 사용해야 한다.
+ 작업 창이 부드럽게 동작해야 한다.(최소화, 최대화, 전환 등등..)
+ 지도는 세 가지 요소, 벽, 수집품, 빈 공간으로 구성되어 있다.
+ 플레이어의 목표는 모든 수집품을 모으고 최소한의 움직임으로 맵을 탈출하는 것이다.
+ 플레이어는 상하좌우로 움직일 수 있어야 한다.
+ 플레이어는 벽을 뚫고 지나갈 수 없다.  
+ 프로그램은 다음의 규칙을 따르며 화면에 이미지를 표현해야 한다.
	+ W, A, S, D 키를 이용해서 플레이어를 조작한다.
	+ ESC는 창을 닫고 게임을 정상적으로 종료한다.
	+ 창 좌상단의 빨간 버튼, 혹은 우상단의 X 버튼은 창을 닫고 게임을 정상적으로 종료한다.  
+ 프로그램은 .ber 확장자 파일을 첫 번째 인자로 받아야 한다.
	+ 지도는 5종류의 문자열로 구성되어야 한다. (0 : 빈 공간, 1 : 벽, C : 수집품, E : 출구, P : 스타팅 포인트)
	+ 지도는 벽으로 둘러싸여 있어야 한다.
	+ 지도는 최소 하나의 출구, 하나의 수집품, 하나의 스타팅 포인트를 포함해야 한다.
	+ 지도는 반드시 직사각형 모양이어야 한다.

## 4. 프로그램
----
|Program name| so_long|
|---|---|
|Turn in files | All your files|
|Makefile | all, clean, fclean, re, bonus|
|Arguments| a map in format *.ber|
|External functs | open, close, read, write, printf, malloc, free, perror, strerror, exit, All functions of the MinilibX|
|Libft authorized | Yes|
|Description | You must create a small 2D game where a dolphin escapes earth after eating some fish. Or any hero collects any valuables before leaving the place.|