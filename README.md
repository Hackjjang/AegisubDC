# 안내
더 나은 대안이 있으므로 더 이상 AegisubDC를 업데이트하지 않음 : [여기(arch1t3cht/Aegisub)](https://github.com/arch1t3cht/Aegisub)에서 확인하세요.

추가 업데이트는 지원되지 않으며, 한글화를 패키지로 제공하기 위한 파생(포크) 입니다.

# Aegisub [Daydream Cafe] Edition

이것은 기본적으로 최신 라이브러리 등을 모두 포함하도록 패치된 wangqr 빌드입니다.

### 유지 관리 안내

이 프로젝트는 더 이상 관리되지 않습니다.

### 변경 사항
- 모든 종속성 업데이트
- 올바른 잘고 텍스트를 표시하는 하프버즈 포함
- 작성 시점에 libass를 `66dba8d`로 업데이트했습니다.
- luajit에서 moonjit으로 전환, 5.3 포함, **5.2 변경 중단되었습니다**.
- 벡터 도구는 이제 소수점 이하 2자리까지 허용합니다.
- 글꼴 관리자(예: 폰트베이스)에서 불러온 글꼴을 허용합니다.
- 텍스트 상자의 테두리 UI를 제거했습니다. 이렇게 하면 더 깔끔해 보입니다.
- gdi에 대한 글꼴 감지를 수정했습니다.
- FFMS2를 수정하여 VP9/Webm 비디오를 허용하고 오디오 패치를 포함합니다.
- WWXD 키프레임 지원 [빛에 의해 요청됨].
- libass에 '실험적 유니 코드 6.3 이상' 대괄호 일치 옵션 추가
- 기본 자동화로 유틸스 모듈 번들 제공
- 현재 글꼴 공급자를 다시 로드하는 새로운 단축키 명령이 추가되었습니다. [기본값: `CTRL+R`]
- VSFilter를 Cyberbeing/xy-VSFilter@fc01a8da5ea6af9091aaab839bc62dc94a90094e로 업데이트했습니다.
- VSFilterMod를 sorayuki/VSFilterMod@R5.2.3 로 업데이트했습니다.
- SRT 시간을 항상 반올림하도록 만들었습니다.
- moex3의 실험적인 비디오 패닝.

버그 제보는 [깃허브 이슈 추적](https://github.com/Ristellise/AegisubDC/issues)에서 확인할 수 있습니다.

이 버전에 대한 지원은 이 문제 페이지에서만 제공됩니다.

### 설치

1. zip 파일의 압축을 별도의 폴더에 풉니다. (프로그램 파일에 Aegisub 폴더가 설치되어 있는 경우, 잘 모르는 경우 이 폴더를 교체하지 않는 것이 좋습니다!).
2. 이전 버전(예: 3.2.2)을 사용하는 경우 구성이 충돌하지 않도록 `config.json`을 다른 파일 이름으로 보관하는 것이 좋습니다(변경 사항이 없어야 하지만 안전을 위해 보관하는 것이 좋습니다.).  
   C:\Users\{YOUR_USERNAME_HERE}\AppData\Roaming\Aegisub\config.json`에서 `config.json`을 찾을 수 있습니다.

### 언어 지원

한국어 현지화만 패키지로 제공하고 있습니다. 한글화만 필요하신 분은 [여기](https://blog.naver.com/jhacker/223182271829)로 와서 받아가십시오.

## Aegisub 빌드

### CMake (윈도 전용)

이 포크에는 소스와 함께 다양한 라이브러리가 모두 포함되어 있으며, 현재 디렉터리를 폴더의 루트로 설정하고 실행합니다: 'scripts\createcmake.bat`를 실행합니다.

AviSynth+ 지원을 활성화하려면 AviSynth를 설치하고 필터 SDK를 체크한 후, createcmake.bat를 수정합니다.

## Moonscript 업데이트

문스크립트 저장소 내에서 `bin/moon bin/splat.moon -l moonscript moonscript/ > bin/moonscript.lua`를 실행합니다.
새로 생성된 `bin/moonscript.lua`를 열고 그 안에서 다음과 같이 변경합니다:

1. 파일의 마지막 줄인 `package.preload["moonscript"]()`에 `return`을 추가하여 `return package.preload["moonscript"]()`를 생성합니다.
2. package.preload['moonscript.base']`의 함수 내에서 `moon_loader`, `insert_loader`, `remove_loader`에 대한 참조를 제거합니다. 즉, 반환된 테이블에서 해당 선언, 정의 및 항목을 제거합니다.
3. package.preload['moonscript']`의 함수 내에서 `_with_0.insert_loader()` 줄을 제거합니다.

이제 파일을 사용할 준비가 되었으며, Aegisub 저장소 내의 `automation/include`에 배치할 수 있습니다.

## 라이선스

이 리포지토리에 있는 모든 파일은 다양한 GPL 호환 BSD 스타일 라이선스에 따라 라이선스가 부여됩니다. 자세한 내용은 라이선스 및 개별 소스 파일을 참조하세요.
공식 Windows 빌드는 fftw3를 포함하기 때문에 GPLv2입니다.

## 자주 묻는 질문

질문 : ~~리눅스~~리눅스가 지원되나요?
답변 : 지금은 아니...지만, 미래에는 어쩌면? (하지만 동결)

질문 : 릴리스의 'blurb'라는 이름은 무엇인가요?
답변 : 주로 제가 공개할 때 관심 있는 주제로 무작위로 선정합니다.

질문 : 무작위로 자막이 표시되지 않는 문제가 발생해요! (9212 이하 버전)  
답변 : '옵션 > 고급 > 영상 > 자막 렌더러'에서 비디오 자막 렌더러를 'libass'로 바꿔 보세요.
