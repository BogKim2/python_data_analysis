def find_commands(filename):
    # 찾고자 하는 패턴들을 리스트로 정의
    patterns = [
        "AfxFT232HPortSendCommand",
        "AfxFT232HPortSendMultiCommand",
        "AfxFT232HPortSendAvrCommand"
    ]

    matching_lines = []

    try:
        # UTF-8로 먼저 시도
        with open(filename, 'r', encoding='utf-8') as file:
            for line in file:
                # 각 패턴에 대해 검사
                if any(line.strip().startswith(pattern) for pattern in patterns):
                    matching_lines.append(line.strip())
    except UnicodeDecodeError:
        # UTF-8로 실패하면 CP949(한글 Windows 기본 인코딩)로 시도
        with open(filename, 'r', encoding='cp949') as file:
            for line in file:
                if any(line.strip().startswith(pattern) for pattern in patterns):
                    matching_lines.append(line.strip())

    # 결과 출력
    print("\n=== 찾은 명령어 목록 ===")
    for line in matching_lines:
        print(line)

    # 결과를 파일로 저장
    with open("result.txt", 'w', encoding='utf-8') as output_file:
        for line in matching_lines:
            output_file.write(line + '\n')

    print(f"\n총 {len(matching_lines)}개의 항목을 찾았습니다.")
    print("결과가 result.txt 파일로 저장되었습니다.")


# 실행
if __name__ == "__main__":
    try:
        find_commands("USB_FT232H_Device.cpp")
    except FileNotFoundError:
        print("Error: USB.cpp 파일을 찾을 수 없습니다.")
    except Exception as e:
        print(f"Error: {str(e)}")