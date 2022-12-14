# minitalk

UNIX 시그널을 이용해 데이터를 주고받는 클라이언트-서버 구조의 통신 프로그램 구현

## Mandatory part

클라이언트와 서버로 이루어진 통신 프로그램을 구현하는 것이다.

서버가 먼저 실행되어야 하며, 서버는 자기 자신의 PID를 출력하고, 클라이언트는 서버의 PID와 서버로 전송할 문자열을 인자로 받는다.

클라이언트는 인자로 들어온 문자열을 서버로 전송하고, 서버는 문자열을 수신받은 후 이를 출력한다.

프로세스 간 통신은 UNIX 시그널을 이용해서만 이루어져야 한다.

```SIGUSR1```과 ```SIGUSR2``` 단 두 개의 시그널만 사용해야 한다.

## Bonus part

서버는 시그널이 들어올 때마다 클라이언트에 답장 시그널을 보내는 것으로 시그널이 잘 수신되었음을 보장해야 한다.

유니코드 문자도 지원

## 구현

```SIGUSR1```과 ```SIGUSR2``` 단 두개의 시그널로만 데이터를 전송해야하다보니 데이터를 비트단위로 쪼개 전송한다.

- ```"ABC"``` -> ```01000001 01000010 01000011 00000000``` (마지막은 NULL 문자 '\0')

전송할 비트가 1인 경우 ```SIGUSR1```을, 0인 경우 ```SIGUSR2```를 전송한다.

서버는 클라이언트로부터 비트 단위로 시그널 신호를 받아 1 바이트 씩 출력해준다. (유니코드 문자의 경우 터미널에서 알아서 표시하므로 1 바이트 씩 출력해도 문자열이 깨지지 않고 출력 된다.)


### 주의할 점

아직 시그널을 처리하는 도중에 시그널이 계속 들어올 경우 누락이 발생할 수 있음.
> 리눅스 시스템은 같은 유형의 시그널이 이미 보류 중일 경우 시그널을 대기열에 넣지 않는다.

### 해결 방법

최대한 핸들러를 짧게 작성하고, 서버에서 응답 시그널을 통해 재전송을 요청한다.

시그널 처리 방식

- 서버의 처리가 성공한 경우, ```SIGUSR1```을 전송해 클라이언트에 성공을 알린다.   
(클라이언트는 수신받은 후 다음 시그널 전송)
- 서버의 처리가 실패한 경우, ```SIGUSR2```를 전송해 클라이언트에 실패를 알린다.   
(클라이언트는 수신받은 후 동일 시그널 재전송)

## 실행 결과

client와 server를 컴파일 후 서버 먼저 실행
```shell
$>make
$>./server
PID : 61922
```

client는 다음과 같이 실행 (서버의 PID와 서버로 전송할 문자열을 인자로 받음)
```shell
$>./client 61922 "hello world 1"
$>./client 61922 "hello world 2"
$>./client 61922 "hello world 3"
```

server에서는 문자열을 잘 수신받았는지 출력 확인
```shell
$>./server
PID : 61922
hello world 1
hello world 2
hello world 3
```