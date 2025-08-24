// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ATPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPARTY_API AATPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    AATPGameModeBase();

    // 맵 로드 직후, 게임 규칙/옵션 파싱 등에 가장 먼저 호출됨
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

    // 월드가 준비되고 ‘게임 시작’ 직전 호출(싱글/호스트 기준)
    virtual void StartPlay() override;

    // 플레이어가 들어왔을 때(로컬/서버에서 컨트롤러 생성 직후)
    virtual void PostLogin(APlayerController* NewPlayer) override;

    // 플레이어가 나갈 때
    virtual void Logout(AController* Exiting) override;

    // 스폰 지점 선택 로직(플레이어 시작 위치 커스텀)
    virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

    // 플레이어 리스폰/첫 스폰 로직
    virtual void RestartPlayer(AController* NewPlayer) override;

protected:
    // 맵 옵션에서 받아온 시작 태그(예: ?StartTag=A)
    UPROPERTY(VisibleInstanceOnly, Category="Match")
    FString StartTagOption;

    // 최대 플레이어 수 같은 간단한 규칙 변수
    UPROPERTY(EditDefaultsOnly, Category="Match")
    int32 MaxPlayers = 1;

    // (선택) 첫 스폰 전에 준비해야 하는 전역 리소스/데이터 로딩 훅
    virtual void PrewarmSystems();

    // StartTag와 일치하는 PlayerStart를 찾아줌
    APlayerStart* FindTaggedPlayerStart(const FString& InTag) const;

    // 랜덤 또는 기본 PlayerStart 반환
    APlayerStart* FindDefaultPlayerStart() const;
};
