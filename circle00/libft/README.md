# libft 
## -Your very first own library-
> 나만의 라이브러리를 만들자.
## 1. 프로젝트 소개
-----
42seoul 프로젝트를 수행할 때는 프로젝트에서 명시한 허용 함수만을 사용할 수 있으며, 그 숫자는 매우 적다.  
이번 프로젝트는 앞으로의 프로젝트에서 사용할 함수를 구현하는 것이다. 구현하는 함수 대부분이 이미 C언어에서 구현된 함수이며 이 프로젝트를 통해 함수의 동작에 관해 더 깊은 이해를 얻게 될 것이다.

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
+ 전역 변수의 사용은 금지된다.
+ 복잡한 함수 작성을 위해 하위 함수가 필요한 경우 static 함수로 지정해야 한다.
+ libft.a 라는 이름의 아카이브 파일이 루트 레포지토리에 생성되어야 한다.

## 4. 함수 리스트
-----
lbift 라이브러리의 함수는 다음의 세 파트로 이루어져 있다.
  
### part 1 - Libc function
+ isalpha
+ isdigit
+ isalnum
+ isascii
+ isprint
+ strlen
+ memset
+ bzero
+ memcpy
+ memmove
+ strlcpy
+ strlcat
+ toupper
+ tolower
+ strchr
+ strrchr
+ strncmp
+ memchr
+ memcmp
+ strnstr
+ atoi

### part 2 - Additional functions
+ ft_substr
+ ft_strjoin
+ ft_strtrim
+ ft_split
+ ft_itoa
+ ft_strmapi
+ ft_putchar_fd
+ ft_putstr_fd
+ ft_putendl_fd
+ ft_putnbr_fd
### bonus part
+ ft_lstnew
+ ft_lstadd_front
+ ft_lstsize
+ ft_lstlast
+ ft_lstadd_back
+ ft_lstdelone
+ ft_lstclear
+ ft_lstiter
+ ft_lstmap
