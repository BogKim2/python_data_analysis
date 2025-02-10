import pandas as pd


def categorize_commands():
    try:
        # 일반 텍스트 파일로 읽기
        with open('result2.txt', 'r', encoding='utf-8') as file:
            commands = [line.strip() for line in file if line.strip()]

        # DataFrame 생성
        df = pd.DataFrame(commands, columns=['command'])

        # 각 카테고리별로 필터링
        basic_commands = df[df['command'].str.startswith('AfxFT232HPortSendCommand')].sort_values('command')
        multi_commands = df[df['command'].str.startswith('AfxFT232HPortSendMultiCommand')].sort_values('command')
        avr_commands = df[df['command'].str.startswith('AfxFT232HPortSendAvrCommand')].sort_values('command')

        # 결과 출력 및 저장
        with open('resutls3.txt', 'w', encoding='utf-8') as f:
            # Basic Commands
            f.write("=== AfxFT232HPortSendCommand ===\n")
            print("\n=== AfxFT232HPortSendCommand ===")
            for cmd in basic_commands['command']:
                print(cmd)
                f.write(cmd + '\n')

            # Multi Commands
            f.write("\n=== AfxFT232HPortSendMultiCommand ===\n")
            print("\n=== AfxFT232HPortSendMultiCommand ===")
            for cmd in multi_commands['command']:
                print(cmd)
                f.write(cmd + '\n')

            # AVR Commands
            f.write("\n=== AfxFT232HPortSendAvrCommand ===\n")
            print("\n=== AfxFT232HPortSendAvrCommand ===")
            for cmd in avr_commands['command']:
                print(cmd)
                f.write(cmd + '\n')

            # 통계 정보
            f.write("\n=== 통계 ===\n")
            f.write(f"기본 명령어: {len(basic_commands)} 개\n")
            f.write(f"멀티 명령어: {len(multi_commands)} 개\n")
            f.write(f"AVR 명령어: {len(avr_commands)} 개\n")
            f.write(f"총 명령어: {len(df)} 개\n")

            # 통계 정보 출력
            print("\n=== 통계 ===")
            print(f"기본 명령어: {len(basic_commands)} 개")
            print(f"멀티 명령어: {len(multi_commands)} 개")
            print(f"AVR 명령어: {len(avr_commands)} 개")
            print(f"총 명령어: {len(df)} 개")

        print("\n결과가 results3.txt 파일로 저장되었습니다.")

    except FileNotFoundError:
        print("Error: result2.txt 파일을 찾을 수 없습니다.")
    except Exception as e:
        print(f"Error: {str(e)}")


# 실행
if __name__ == "__main__":
    categorize_commands()