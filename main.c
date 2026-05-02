//1.주석
/*
	파일명: main.c
	작성자: 이시현
	하는일: 우주 먼지 토끼 키우기 - 1차
*/

//2. 전처리기
#include <stdio.h>
#include <stdlib.h>

//3. int main()

int main()
{
	system ("chcp 65001");
	//1. 1차 변수 선언
    char rabbit_initial;      // 토끼의 이니셜
    double current_mass;    // 현재 토끼의 질량 (kg)
    int stardust_count;    // 수집한 별가루 개수
    double increased_mass;  // 증가한 질량
    int twinkle_power;      // 반짝임 지수
    
    //1-1. 2차 추가 변수(미리 선언)
    int affection = 0;     // 애정 지수 (초기값 0)
    int stress = 0;        // 스트레스 (초기값 0)
    int color_temp = 3000;  // 색온도 (초기값 4000K, 백색)
    double energy = 100.00;  // 보유 에너지 (초기값 100.0)
    double density;         // 밀도 (질량과 관련하여 계산 예정, 결과값)

    // 2. 데이터 입력
    printf("  * .  * .  * .  * .  * .  * .  * \n");
    printf(" ( /) /)  [우주 먼지 토끼 통신 가동] \n");
    printf(" ( . .)   토끼의 이름은 무엇인가요?: ");
    scanf(" %c", &rabbit_initial);

    printf(" ( >♡<)   현재 토끼의 질량(kg)은?: ");
    scanf("%lf", &current_mass);

    printf(" ( u u)   오늘 먹은 별가루는 몇 개인가요?: ");
    scanf("%d", &stardust_count);
    printf("  * .  * .  * .  * .  * .  * .  * \n");

    // 3. 산술 연산
    increased_mass = current_mass + (stardust_count * 0.12); //별가루 1개당 기존 질량 + 0.12kg
    twinkle_power = stardust_count * 7; // 반짝임 지수는 별 가루 개수에 7을 곱한 값으로 설정
    density = energy / increased_mass; // 밀도: 에너지 / 최종 질량으로 설정

    // 4. 결과 출력 //추가 변수도 함께 > 현재 토끼의 상태 출력
    printf("\n--- ★ 은하 먼지 토끼 %c의 리포트 ★ ---\n", rabbit_initial);
    printf("  * .  * .  * .  * .  * .  * .  * \n");
    printf("  질량 변화: %.1f kg -> %.1f kg\n", current_mass, increased_mass);
    printf("  반짝임 지수: %d pt\n", twinkle_power);
    printf("  밀도: %.2f dust\n", density); //dust는 게임 내 토끼의 밀도를 나타내는 가상단위임!
    printf("  에너지 잔량: %.2f %%\n", energy);
    printf("  [애정: %d | 스트레스: %d | 색온도: %d K]\n", affection, stress, color_temp);
    printf("  * .  * .  * .  * .  * .  * .  *");
    printf("\n-------------------------------------\n \n");
    printf("상태 분석이 완료되었습니다. 멋진 별토끼가 될 준비 중!\n");

    return 0;

    //1. 조건문
	//1-1. Switch로 행동 선택하기
	printf("\n[ 오늘은 무엇을 할까요? ]\n");
    printf("1. 별가루 폭식  2. 쓰다듬기  3. 블랙홀 산책  4. 심해 은하 휴식\n");
    printf("선택: ");
    scanf("%d", &choice);
    
	switch(choice)
	{
		case 1:
			printf("토끼의 몸집이 커졌습니다! 앗, 너무 많이 먹었나? \n");
			printf("  * .  *  .  *  .  *  .  *  .  * \n");
            printf("*    .  /) /)  *  .   *    .   * \n");
            printf("  . *  (  . .)  .  *    .    * \n");
            printf("  *    (  > <)    .     *  .   * \n");
            printf("  *  .  *  .  *  .  *  .  *  .  * \n");
			printf("[ 질량 ↑, 에너지 ↑↑↑, 스트레스 ↑↑ ]\n");
			
			increased_mass += 10.0; 
			energy += 30.0;
			break;
		
		case 2:
			printf("쓰담쓰담, 토끼의 기분이 좋아 보입니다! \n");
			printf("  * .  *  .  *  .  *  .  *  .  * \n");
            printf("  ♡   *  /) /)  .  *    ♡   .  * \n");
            printf("  *  .  ( ^ ^)  ♡  .  *      * \n");
            printf("  *   ♡ ( u u) .  *  .   ♡     * \n");
            printf("  *  .  *  .  *  .  *  .  *  .  * \n");
			printf("[ 애정 ↑↑, 스트레스 ↓↓ ]\n");
			
			affection += 20;
			stress -= 15;	
			break;
		
		case 3:
			
			printf("블랙홀 주변을 산책합니다. 토끼는 끝이 보이지 않는 어둠 속에서 알 수 없는 끌림과 긴장감을 느낍니다.. \n");
			printf("  * .  * .  * .  * .  * .  * .  * \n");
            printf("  *     .  o  .   (\\ /)   .    . \n");
            printf("  .   O   .  o   (ㅇ ㅇ)    O  * \n");
            printf(" *      .  O  .  (  > <)  *    . \n");
            printf("  * .  * .  * .  * .  * .  * .  * \n");
			printf("[ 색온도 ↑↑, 에너지 ↓↓, 스트레스 ↑ ]\n");
			
			color_temp += 2000; // 온도가 높아질수록 한색에 가까워짐
			energy -= 20.0;
			stress += 15;
			break;
			
		case 4:
			printf("고요한 심해 은하에서 휴식합니다. 토끼는 마음이 편안해짐을 느낍니다..\n");
			printf("  * .  * .  * .  * .  * .  * .  * \n");
			printf("  *  .   *  . /) /) . z Z   *  . \n");
            printf(".   * .   * (- - ) * .   * .   \n");
            printf(" * .   * .  (  u ).   * .   *  \n");
			printf("  * .  * .  * .  * .  * .  * .  * \n");
			printf("[ 색온도 ↓↓, 에너지 ↑, 스트레스 ↓↓ ]\n");
			
			stress -= 20;
			color_temp -= 2000; // 온도가 낮아질수록 난색에 가까워짐
			energy += 10.0;
			break;	
	}

	//1-2. 진화 등급 판정
	printf("\n[ 최종 진화 등급 판정 ]\n");

	
}
