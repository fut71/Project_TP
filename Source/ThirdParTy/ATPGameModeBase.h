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

    // �� �ε� ����, ���� ��Ģ/�ɼ� �Ľ� � ���� ���� ȣ���
    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

    // ���尡 �غ�ǰ� ������ ���ۡ� ���� ȣ��(�̱�/ȣ��Ʈ ����)
    virtual void StartPlay() override;

    // �÷��̾ ������ ��(����/�������� ��Ʈ�ѷ� ���� ����)
    virtual void PostLogin(APlayerController* NewPlayer) override;

    // �÷��̾ ���� ��
    virtual void Logout(AController* Exiting) override;

    // ���� ���� ���� ����(�÷��̾� ���� ��ġ Ŀ����)
    virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

    // �÷��̾� ������/ù ���� ����
    virtual void RestartPlayer(AController* NewPlayer) override;

protected:
    // �� �ɼǿ��� �޾ƿ� ���� �±�(��: ?StartTag=A)
    UPROPERTY(VisibleInstanceOnly, Category="Match")
    FString StartTagOption;

    // �ִ� �÷��̾� �� ���� ������ ��Ģ ����
    UPROPERTY(EditDefaultsOnly, Category="Match")
    int32 MaxPlayers = 1;

    // (����) ù ���� ���� �غ��ؾ� �ϴ� ���� ���ҽ�/������ �ε� ��
    virtual void PrewarmSystems();

    // StartTag�� ��ġ�ϴ� PlayerStart�� ã����
    APlayerStart* FindTaggedPlayerStart(const FString& InTag) const;

    // ���� �Ǵ� �⺻ PlayerStart ��ȯ
    APlayerStart* FindDefaultPlayerStart() const;
};
