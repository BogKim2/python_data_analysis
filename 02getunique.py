import pandas as pd


def clean_command(line):
    # 라인에서 주석 부분 제거
    if '//' in line:
        # 주석 이전 부분만 가져오기
        line = line.split('//')[0]

    # 양쪽 공백 제거
    return line.strip()


def process_commands():
    try:
        # result.txt 파일 읽기
        with open('result.txt', 'r', encoding='utf-8') as file:
            lines = file.readlines()

        # 주석 처리 및 빈 줄 제거
        filtered_lines = []
        for line in lines:
            # 라인이 '//'로 시작하지 않는 경우만 처리
            if not line.strip().startswith('//'):
                cleaned = clean_command(line)
                # 비어있지 않은 라인만 추가
                if cleaned:
                    filtered_lines.append(cleaned)

        # pandas DataFrame 생성
        df = pd.DataFrame(filtered_lines, columns=['command'])

        # 중복 제거
        unique_commands = df['command'].unique()

        # 결과 출력
        print("\n=== Unique 명령어 목록 ===")
        for cmd in unique_commands:
            print(cmd)

        # result2.txt로 저장
        with open('result2.txt', 'w', encoding='utf-8') as output_file:
            for cmd in unique_commands:
                output_file.write(cmd + '\n')

        print(f"\n총 {len(unique_commands)}개의 unique 명령어를 찾았습니다.")
        print("결과가 result2.txt 파일로 저장되었습니다.")

    except FileNotFoundError:
        print("Error: result.txt 파일을 찾을 수 없습니다.")
    except Exception as e:
        print(f"Error: {str(e)}")


# 실행
if __name__ == "__main__":
    process_commands()