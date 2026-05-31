//1.주석
/*
	파일명: main.c
	작성자: 이시현
	하는일: 우주 먼지 토끼 키우기 - 3차
*/

//2. 전처리기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//3. 전역 변수 선언
int achievement_count = 0;  // 달성한 업적 개수를 체크하는 변수
int rank_score = 0;         // 등급을 숫자로 저장
int twinkle_power;          // 반짝임 지수
double increased_mass;      // 증가한 질량
double density;             // 밀도
double energy = 100.00;		// 보유 에너지 (초기값 100.0)
int affection = 0;          // 애정 지수 (초기값 0)
int stress = 0;             // 스트레스 (초기값 0)
int color_temp = 4000;      // 색온도 (초기값 4000K, 백색)

//4. 함수 정의
//4-1.데이터 범위 보정 및 산술 연산-함수 처리
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
		energy = 200.0;   	   // 에너지 최댓값 제한
	}
    if (energy < 0) 
	{
		energy = 0.0;         //에너지는 최솟값이 0이다.
	}
	if (affection > 200) 
	{
		affection = 200;         //애정 지수 최댓값 제한.
	}

    //산술 연산(함수 내에서 전역 변수 값을 직접 변경)
    density = energy / increased_mass;							// 밀도: 에너지 / 최종 질량으로 설정 및 업데이트  
}

//4-2. 진화 등급 판정-함수 처리
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
	{
    	printf("최종 등급: [ D ] \n");
    	rank_score = 1;
    } 
    else 
	{
    	printf("최종 등급: [ F ] \n");
    	rank_score = 0;
    }
   
    return rank_score;
    
}
	
        
//4-3. 업적 및 칭호 부여-함수 처리
void grant_achievements()
{
	printf("\n[ 업적 및 칭호 부여 ]\n");
	if (rank_score >= 6 && twinkle_power >= 700 && affection >= 100 && stress <= 50)
	{
    	printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 은하계의 아이돌 [ RANK [ SS ] 이상 | 반짝임 700 이상 | 애정 100%% 이상 | 스트레스 50%% 이하 ]\n");
        achievement_count++;
	}
	
    if ( rank_score >= 4 && twinkle_power >= 500 && affection >= 150) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 따스한 햇살 [ RANK [ A ] 이상 | 반짝임 500 이상 | 애정 150 %% 이상 ] \n");
        achievement_count++;
	}
	
    if (density >= 80.0) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 고밀도 초신성 [ 밀도 80 이상 ] \n");
        achievement_count++;
	}
	
    if (increased_mass >= 500.0) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 요새 덩어리 [ 질량 500kg 이상 ] \n");
        achievement_count++;
    }
    
    if (stress >= 100) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 블랙홀 토끼 [ 스트레스 100 %% 이상 ] \n");
        achievement_count++;
    }
    
    if (color_temp <= 3000) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 뜨거운 적색거성 [ 색온도 3000K 이하 ] \n");
        achievement_count++;
    }
    
    if (color_temp >= 7000) 
	{
        printf("축하드립니다! 업적을 달성했습니다!");
		printf(" ★ 푸른 다이아몬드 성단 [ 색온도 7000K 이상 ] \n");
        achievement_count++;
    }
    
    if (achievement_count == 0)
    {
    	printf("아직 달성한 업적이 없습니다. 더 노력해보세요! \n");
	}

}


//5. int main()
int main()
{
	system ("chcp 65001");
	
	//1. 1차(기본) 변수 선언-지역 변수
    char rabbit_initial;		// 토끼의 이니셜
    double current_mass;		// 현재 토끼의 질량 (kg)
    int stardust_count;			// 수집한 별가루 개수
    
    //1-1. 2차(조건문) 변수 선언-지역 변수
    int choice = 0;					// 행동 선택
    
	//1-2. 3차(반복문) 변수 선언-지역 변수
    int event_roll = rand() % 100; //0~99 중 랜덤 숫자 뽑기
    int found_dust = 0; //탐사 게임에서 찾은 별가루 개수    

    // 2. 데이터 입력
    printf("  * .  * .  * .  * .  * .  * .  * \n");
    printf("  /) /)  [우주 먼지 토끼 통신 가동] \n");
    printf(" ( . .)   토끼의 이름은 무엇인가요?: ");
    scanf(" %c", &rabbit_initial);

    printf(" ( >♡<)   현재 토끼의 질량(kg)은?: ");
    scanf("%lf", &current_mass);

    printf(" ( u u)   오늘 먹은 별가루는 몇 개인가요?: ");
    scanf("%d", &stardust_count);
    printf("  * .  * .  * .  * .  * .  * .  * \n");

    // 3. 산술 연산
    update_and_adjust_stats(current_mass, stardust_count);
    
    // 4. 결과 출력 - 추가 변수도 함께 >> 현재 토끼의 상태 출력
    printf("\n--- ★ 은하 먼지 토끼 %c의 리포트 ★ ---\n", rabbit_initial);
    printf("  * .  * .  * .  * .  * .  * .  * \n");
    printf("  질량 변화: %.1f kg -> %.1f kg \n", current_mass, increased_mass);
    printf("  반짝임 지수: %d pt \n", twinkle_power);
    printf("  밀도: %.2f dust \n", density); 					// dust는 게임 내 토끼의 밀도를 나타내는 가상단위임!
    printf("  에너지 잔량: %.2f %% \n", energy);
    printf("  [애정: %d %% | 스트레스: %d %% | 색온도: %d K]\n", affection, stress, color_temp);
    printf("  * .  * .  * .  * .  * .  * .  *");
    printf("\n-------------------------------------\n \n");
    printf("상태 분석이 완료되었습니다. 멋진 별토끼가 될 준비 중!\n");
    
//1. 반복문
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
        printf("\n[ 육성을 종료하고 최종 결과를 확인합니다. ]\n");
        break; 
    }
    
	switch(choice)
	{
		case 1:
			printf("\n 토끼의 몸집이 커졌습니다! 앗, 너무 많이 먹었나? \n");
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
			printf("\n 쓰담쓰담, 토끼의 기분이 좋아 보입니다! \n");
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
			
			printf("\n 블랙홀 주변을 산책합니다. 토끼는 끝이 보이지 않는 어둠 속에서 알 수 없는 끌림과 긴장감을 느낍니다.. \n");
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
			printf("\n 고요한 심해 은하에서 휴식합니다. 토끼는 마음이 편안해짐을 느낍니다..\n");
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
		
		case 5:
			printf("\n=============================================\n");
            printf("\n            [우주 탐사 미니게임]     \n");
            printf("\n=============================================\n");
            printf("토끼가 탐사선을 타고 미지의 성단으로 출발합니다! \n\n");
			printf("  .  \n\n");
			printf("  .  \n\n");
			printf("  ★  \n\n");	
            printf("\n성단 주변을 탐색하며 별가루 레이더를 가동합니다.\n");

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
	
	//데이터 보정 및 최종 상태 계산
	update_and_adjust_stats(current_mass, stardust_count);
    
}

    // 모든 수치 재출력 (최종 스탯 확인)
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
    
    
    // 1-2. 진화 등급 판정 (매개변수로 질량과 반짝임을 보내고, 결과 스코어를 리턴받음)
    rank_score = judge_evolution(increased_mass, twinkle_power); 
	
	// 1-3. 업적 및 칭호 부여 (함수 호출 호출! 내부에서 전역변수 직접 변경)
    grant_achievements();
    
    return 0;
}
