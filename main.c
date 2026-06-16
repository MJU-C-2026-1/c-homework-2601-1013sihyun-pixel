//1.주석
/*
	파일명: main.c
	작성자: 이시현
	하는일: 우주 먼지 토끼 키우기 - 4차
*/

//2. 전처리기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RABBITS 10  // 최대 관리 가능한 토끼 수

//3. 데이터 저장용 배열 선언
char rabbit_initials[MAX_RABBITS];    //토끼들의 이니셜 저장 배열 (오타 수정)
double increased_masses[MAX_RABBITS]; //최종 질량 저장 배열
int stardust_counts[MAX_RABBITS];     //수집한 별가루 개수 저장 배열
int twinkle_powers[MAX_RABBITS];      //반짝임 지수 저장 배열
double densities[MAX_RABBITS];         //밀도 저장 배열
double energies[MAX_RABBITS];          //최종 에너지 저장 배열
int stresses[MAX_RABBITS];             //최종 스트레스 저장 배열

//4. 전역 변수 선언
int achievement_count = 0;  // 달성한 업적 개수를 체크하는 변수
int rank_score = 0;         // 등급을 숫자로 저장
int twinkle_power;          // 반짝임 지수
double increased_mass;      // 증가한 질량
double density;             // 밀도
double energy = 100.00;     // 보유 에너지 (초기값 100.0)
int affection = 0;          // 애정 지수 (초기값 0)
int stress = 0;             // 스트레스 (초기값 0)
int color_temp = 4000;      // 색온도 (초기값 4000K, 백색)
int rabbit_count = 0;       // 현재 등록된 총 토끼 수
int current_idx = -1;       // 현재 선택되어 육성 중인 토끼의 인덱스
char rabbit_initial;        // 토끼의 이니셜
double current_mass;        // 현재 토끼의 질량 (kg)
int stardust_count;         // 수집한 별가루 개수

//5. 함수 선언
void register_new_rabbit();
void update_and_adjust_stats(double current_mass, int stardust_count);
void analyze_all_rabbits(double *mass_ptr, double *energy_ptr, int *stress_ptr, double *density_ptr, int count);
int judge_evolution(double mass, int twinkle);
int judge_evolution_param(double *mass_arr, int *twinkle_arr, int idx);
void grant_achievements();
void print_report();

//6. int main()
int main()
{
	system("chcp 65001");
	srand(time(NULL)); // 랜덤 시드 설정
	
	//1. 지역 변수 선언
	//1-1. 2차(조건문) 변수 선언-지역 변수
	int choice = 0;         // 행동 선택
	
	//1-2. 3차(반복문) 변수 선언-지역 변수
	int event_roll = 0;     // 0~99 중 랜덤 숫자 뽑기 변수
	int found_dust = 0;     // 탐사 게임에서 찾은 별가루 개수    

	//1-3. 4차(메인 시스템 루프용) 변수 선언-지역 변수
	int system_choice = 0;

	//2. 메인 시스템 루프-성단 관리 시스템
	while(1)
	{
		printf("\n+=========================================================+\n");
		printf("|       [ SYSTEM : RAISING SPACE DUST RABBIT ]            |\n");
		printf("+=========================================================+\n");
		printf("  1. LAUNCH : 새로운 우주 먼지 토끼 등록 및 육성 [%d / %d]\n", rabbit_count, MAX_RABBITS);
		printf("  2. SHUTDOWN : 성단 관리 시스템 종료 (종합 분석 리포트)\n");
		printf("+=========================================================+\n");
		printf(" ▶ COMMAND SELECT : ");
		scanf("%d", &system_choice);

		if(system_choice == 2)
		{
			printf("\n[ 시스템 제어를 종료하고 최종 성단 리포트를 출력합니다. ]\n");
			break;
		}
		else if(system_choice == 1)
		{
			if(rabbit_count >= MAX_RABBITS) //성단 자리 체크 후 실행
			{
				printf("\n[ 알림: 성단이 가득 찼습니다! 더 이상 토끼를 수용할 수 없습니다. (최대 %d마리) ]\n", MAX_RABBITS);
				printf("\n[ 알림: 더 이상 등록이 불가능하므로, 자동으로 종합 정산 리포트를 출력합니다.]\n");
				break;
			}
			else
			{
				register_new_rabbit(); //새 우주 토끼 등록

				// 1. 반복문
				while(1)
				{
					//1. 조건문
					//1-1. Switch로 행동 선택하기
					printf("\n[ 오늘은 무엇을 할까요? ]\n");
					printf("1. 별가루 폭식  2. 쓰다듬기  3. 블랙홀 산책  4. 심해 은하 휴식 5. 우주 탐사 6. 나가기\n");
					printf("\n선택: ");
					scanf("%d", &choice);
					
					if (choice == 6)
					{
						printf("\n[ 육성을 종료하고 최종 결과를 정산하여 성단에 저장합니다. ]\n");
						break; 
					}
					
					switch(choice)
					{
						case 1:
							printf("\n 토끼의 몸집이 커졌습니다! 앗, 너무 많이 먹었나? \n");
							printf("  * .  * .  * .  * .  * .  * \n");
							printf("* .  /) /)  * .   * .   * \n");
							printf("  . * (  . .)  .  * .    * \n");
							printf("  * (  > <)    .     * .   * \n");
							printf("  * .  * .  * .  * .  * .  * \n");
							printf("[ 질량 증가, 에너지 증가, 스트레스 증가 ]\n");
							
							increased_mass += 10.0; 
							energy += 30.0;
							stress += 15;
							break;
						
						case 2:
							printf("\n 쓰담쓰담, 토끼의 기분이 좋아 보입니다! \n");
							printf("  * .  * .  * .  * .  * .  * \n");
							printf("  ♡   * /) /)  .  * ♡   .  * \n");
							printf("  * .  ( ^ ^)  ♡  .  * * \n");
							printf("  * ♡ ( u u) .  * .   ♡     * \n");
							printf("  * .  * .  * .  * .  * .  * \n");
							printf("[ 애정 증가, 스트레스 감소 ]\n");
							
							affection += 20;
							stress -= 15;	
							break;
						
						case 3:
							printf("\n 블랙홀 주변을 산책합니다. 토끼는 끝이 보이지 않는 어둠 속에서 알 수 없는 끌림과 긴장감을 느낍니다.. \n");
							printf("  * .  * .  * .  * .  * .  * .  * \n");
							printf("  * .  o  .   (\\ /)   .    . \n");
							printf("  .    O   .  o   (ㅇ ㅇ)    O  * \n");
							printf(" * .  O  .  (  > <)  * . \n");
							printf("  * .  * .  * .  * .  * .  * .  * \n");
							printf("[ 색온도 증가, 에너지 감소, 스트레스 증가 ]\n");
							
							color_temp += 2000; // 온도가 높아질수록 한색에 가까워짐
							energy -= 20.0;
							stress += 15;
							break;
							
						case 4:
							printf("\n 고요한 심해 은하에서 휴식합니다. 토끼는 마음이 편안해짐을 느낍니다..\n");
							printf("  * .  * .  * .  * .  * .  * .  * \n");
							printf("  * .   * . /) /) . z Z   * . \n");
							printf(".   * .   * (- - ) * .   * .   \n");
							printf(" * .   * .  (  u ).   * .   * \n");
							printf("  * .  * .  * .  * .  * .  * .  * \n");
							printf("[ 색온도 감소, 에너지 증가, 스트레스 감소 ]\n");
							
							stress -= 20;
							color_temp -= 2000; // 온도가 낮아질수록 난색에 가까워짐
							energy += 10.0;
							break;
						
						case 5:
							printf("\n=============================================\n");
							printf("\n            [우주 탐사 미니게임]     \n");
							printf("\n=============================================\n");
							printf("토끼가 탐사선을 타고 미지의 성단으로 출발합니다! \n\n");
							printf("  .  \n\n");
							printf("  .  \n\n");
							printf("  ★  \n\n");	
							printf("\n성단 주변을 탐색하며 별가루 레이더를 가동합니다.\n");

							event_roll = rand() % 100; //주사위 굴리기

							if (event_roll < 50) // 50% 확률: 일반 성공
							{
								found_dust = (rand() % 5) + 3; // 3~7개 랜덤
								printf("\n반짝이는 황금빛 성단을 발견했습니다!\n");
								printf("( . .)  주섬주섬.. 토끼가 열심히 별가루를 주워 담습니다.\n");
								printf("[ 별가루 +%d개 획득! ]\n", found_dust);
							}
							else if (event_roll < 85) // 35% 확률: 대박 크리티컬
							{
								found_dust = (rand() % 8) + 10; // 10~17개 랜덤
								printf("\n'초신성 잔해 지대'를 발견했습니다!\n");
								printf("( >♡<)  세상에! 사방이 온통 별가루 천지입니다!\n");
								printf("[ 크리티컬! 별가루 +%d개 대량 획득! ]\n", found_dust);
								stress -= 5; 
							}
							else // 15% 확률: 꽝 (돌발 사고)
							{
								found_dust = 1; 
								printf("\n콰과광! 갑작스러운 소행성 소나기를 만났습니다!\n");
								printf("  ( ㅇ ㅇ)  으악! 토끼가 허둥지둥 도망치며 스트레스를 받습니다.\n");
								printf("  [ 탐사 실패.. 별가루는 겨우 %d개만 챙겼습니다. ]\n", found_dust);
								stress += 25; 
							}

							// 획득한 별가루 개수 반영
							stardust_count += found_dust;
							
							// 미니게임 직후 실시간 연산 업데이트
							increased_mass = current_mass + (stardust_count * 0.12);
							twinkle_power = stardust_count * 7;
							
							break;
							
						default:
							printf("\n[ 잘못된 선택입니다. 1~6 사이의 숫자를 눌러주세요. ]\n");
							break;
					}
					
					//2. 데이터 보정 및 최종 상태 계산
					update_and_adjust_stats(current_mass, stardust_count);
				} // ▶ 내부 무한 루프 끝

				//3. 정산
				//3-1. 모든 수치 재출력 (최종 스탯 확인)
				printf("\n--- ★ 은하 먼지 토끼 %c의 최종 스탯 리포트 ★ ---\n", rabbit_initial);
				printf("  * .  * .  * .  * .  * .  * .  * \n");
				printf("  질량: %.1f kg \n", increased_mass);
				printf("  반짝임 지수: %d pt \n", twinkle_power);
				printf("  밀도: %.2f dust \n", density); 
				printf("  에너지 잔량: %.2f %% \n", energy);
				printf("  [애정: %d %% | 스트레스: %d %% | 색온도: %d K]\n", affection, stress, color_temp);
				printf("  * .  * .  * .  * .  * .  * .  *");
				printf("\n-------------------------------------------\n \n");
				printf("상태 분석이 완료되었습니다. 위 수치를 바탕으로 최종 진화 등급을 산출합니다.\n");
				
				// 3-2. 진화 등급 판정 (매개변수로 질량과 반짝임을 보내고, 결과 스코어를 리턴받음)
				rank_score = judge_evolution(increased_mass, twinkle_power); 
				
				// 3-3. 업적 및 칭호 부여 (함수 호출 호출! 내부에서 전역변수 직접 변경)
				grant_achievements();

				//4. 최종 데이터 배열에 저장
				// 4-1. 성단 저장 위치 지정 및 데이터 저장
				current_idx = rabbit_count; // 현재 저장할 방 번호 지정
				rabbit_initials[current_idx] = rabbit_initial;
				increased_masses[current_idx] = increased_mass;
				stardust_counts[current_idx] = stardust_count;
				twinkle_powers[current_idx] = twinkle_power;
				densities[current_idx] = density;
				energies[current_idx] = energy;
				stresses[current_idx] = stress;

				// 4-2. 다음 토끼를 위해 방 번호를 1 증가시키고 저장 완료 알림
				rabbit_count++;
				printf("\n[ 알림: 토끼 '%c'의 스탯이 성단 보관함 %d번 칸에 최종 저장되었습니다! ]\n", rabbit_initial, rabbit_count);
			}
		}
		else
		{
			printf("\n[ 잘못된 선택입니다. 1번이나 2번을 선택해주세요. ]\n");
		}
	}

	// 시스템 종료 후 일괄 리포트 출력 분기
	if (rabbit_count > 0)
	{
		print_report();
	}

	return 0;
}

//7. 함수 정의
//7-1. 신규 우주 토끼 등록-함수 처리
void register_new_rabbit()
{
	//1. 새 토끼를 위한 스탯 완벽 초기화 (이전 판 스탯 누적 방지 보강)
	energy = 100.00;
	affection = 0;
	stress = 0;
	color_temp = 4000;
	achievement_count = 0;
	increased_mass = 0.0;
	stardust_count = 0;

	// 2. 데이터 입력
	printf("\n  * .  * .  * .  * .  * .  * .  * \n");
	printf("  /) /)  [우주 먼지 토끼 통신 가동] \n");
	printf(" ( . .)   토끼의 이름은 무엇인가요?: ");
	scanf(" %c", &rabbit_initial);

	printf(" ( >♡<)   현재 토끼의 질량(kg)은?: ");
	scanf("%lf", &current_mass);

	printf(" ( u u)   오늘 먹은 별가루는 몇 개인가요?: ");
	scanf("%d", &stardust_count);
	printf("  * .  * .  * .  * .  * .  * .  * \n");

	// 3. 산술 연산 함수 호출
	update_and_adjust_stats(current_mass, stardust_count);

	// 4. 결과 리포트 출력
	printf("\n--- ★ 은하 먼지 토끼 %c의 리포트 ★ ---\n", rabbit_initial);
	printf("  질량 변화: %.1f kg -> %.1f kg \n", current_mass, increased_mass);
	printf("  반짝임 지수: %d pt \n", twinkle_power);
	printf("  밀도: %.2f dust \n", density);
	printf("  에너지 잔량: %.2f %% \n", energy);
	printf("  [애정: %d %% | 스트레스: %d %% | 색온도: %d K]\n", affection, stress, color_temp);
	printf("-------------------------------------\n");
}

//7-2. 데이터 범위 보정 및 산술 연산-함수 처리
void update_and_adjust_stats(double current_mass, int stardust_count)
{
	//산술 연산
	increased_mass = current_mass + (stardust_count * 0.12);	// 별가루 1개당 기존 질량 + 0.12kg
	twinkle_power = stardust_count * 7;							// 반짝임 지수는 별 가루 개수에 7을 곱한 값으로 설정
	
	//데이터 범위 보정
	if (stress < 0) 
	{
		stress = 0;				//스트레스 지수는 최솟값이 0이다.
	}

	if (energy > 200.0) 
	{
		energy = 200.0;       // 에너지 최댓값 제한
	}
	if (energy < 0) 
	{
		energy = 0.0;          //에너지는 최솟값이 0이다.
	}
	if (affection > 200) 
	{
		affection = 200;         //애정 지수 최댓값 제한.
	}

	//산술 연산(함수 내에서 전역 변수 값을 직접 변경)
	density = energy / increased_mass;							// 밀도: 에너지 / 최종 질량으로 설정 및 업데이트  
}

//7-3. 진화 등급 판정-함수 처리
int judge_evolution(double mass, int twinkle)
{
	printf("\n[ 최종 진화 등급 판정 ]\n");
	if (increased_mass >= 500 && twinkle_power >= 100) 
	{
		printf("최종 등급: [ SSS ] \n");
		rank_score = 7;
	} 
	else if (increased_mass >= 300 && twinkle_power >= 70) 
	{
		printf("최종 등급: [ SS ] \n");
		rank_score = 6;
	} 
	else if (increased_mass >= 100 && twinkle_power >= 80) 
	{
		printf("최종 등급: [ S ] \n");
		rank_score = 5;
	} 
	else if (increased_mass >= 50 && twinkle_power >= 50) 
	{
		printf("최종 등급: [ A ] \n");
		rank_score = 4;
	} 
	else if (increased_mass >= 30 && twinkle_power >= 30) 
	{
		printf("최종 등급: [ B ] \n");
		rank_score = 3;
	} 
	else if (increased_mass >= 20 && twinkle_power >= 20) 
	{
		printf("최종 등급: [ C ] \n");
		rank_score = 2;
	} 
	else if (increased_mass >= 10 && twinkle_power >= 10)
