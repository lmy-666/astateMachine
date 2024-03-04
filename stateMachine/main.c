// stateMachine.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "statemachine.h"

int main()
{
    printf("Hello World!\n");
    aStateMachine* sm = (aStateMachine*)malloc(sizeof(aStateMachine));
    aStateMachine_Init(sm, "sm");
    aState* s1 = (aState*)malloc(sizeof(aState));
    aState_Init(s1, "s1", aState_excution, aState_entry, aState_exit);
    aState* s2 = (aState*)malloc(sizeof(aState));
    aState_Init(s2, "s2", aState_excution, aState_entry, aState_exit);
    aState* s3 = (aState*)malloc(sizeof(aState));
    aState_Init(s3, "s3", aState_excution, aState_entry, aState_exit);
    aState* s4 = (aState*)malloc(sizeof(aState));
    aState_Init(s4, "s4", aState_excution, aState_entry, aState_exit);
    aStateMachine_addState(sm, s1);
    aStateMachine_addState(sm, s2);
    aStateMachine_addState(sm, s3);
    aStateMachine_addState(sm, s4);

    aStateMachine_start(sm, s1);

    aStateMachine_addTransition1(sm, s1, s2, condition); //[](aStateMachine* sm) {printf("%s condition s1 -> s2", aState_getName(sm->current)); return false; }
    aStateMachine_addTransition1(sm, s1, s3, condition);//[](aStateMachine* sm) {printf("%s condition s1 -> s3", aState_getName(sm->current)); return true; }
    aStateMachine_addTransition1(sm, s2, s3, condition);//[](aStateMachine* sm) {return true; }
    aStateMachine_addTransition1(sm, s3, s4, condition);
    aStateMachine_addTransition1(sm, s4, 0, condition);
    aStateMachine_showStates(sm);

    //update �����״̬��״̬����ִ��excution Ȼ���ж�condtion
    aStateMachine_update(sm);
    aStateMachine_update(sm);
    aStateMachine_update(sm);
    aStateMachine_update(sm);
    aStateMachine_update(sm);

    //std::cout << "Hello World!\n";
    //aStateMachine* sm = new aStateMachine();
    //aState* s1 = new aState("s1", []() ->int {std::cout << "s1 excution" << std::endl; return aStateMachine::stateNone; },
    //    []()->int {std::cout << "s1 entry" << std::endl; return aStateMachine::stateNone; },
    //    []() ->int {std::cout << "s1 exit" << std::endl; return aStateMachine::stateNone; });
    //aState* s2 = new aState("s2", []() ->int {std::cout << "s2 excution" << std::endl; return aStateMachine::stateNone; },
    //    []()->int {std::cout << "s2 entry" << std::endl; return aStateMachine::stateNone; },
    //    []() ->int {std::cout << "s2 exit" << std::endl; return aStateMachine::stateNone; });
    //aState* s3 = new aState("s3", []() ->int {std::cout << "s3 excution" << std::endl; return aStateMachine::stateNone; },
    //    []()->int {std::cout << "s3 entry" << std::endl; return aStateMachine::stateNone; },
    //    []() ->int {std::cout << "s3 exit" << std::endl; return aStateMachine::stateNone; });
    //aState* s4 = new aState("s4", []() ->int {std::cout << "s4 excution" << std::endl; return aStateMachine::stateNone; },
    //    []()->int {std::cout << "s4 entry" << std::endl; return aStateMachine::stateNone; },
    //    []() ->int {std::cout << "s4 exit" << std::endl; return aStateMachine::stateNone; });
    //sm->addState(s1);
    //sm->addState(s2);
    //sm->addState(s3);
    //sm->addState(s4);
    //sm->addTransition(s1, s2, [](aStateMachine* sm) {std::cout << sm->current->getName()<< " condition s1 -> s2" << std::endl; return false; });
    //sm->addTransition(s1, s3, [](aStateMachine* sm) {std::cout << sm->current->getName() << " condition s1 -> s3" << std::endl; return true; });
    //sm->addTransition(s2, s3, [](aStateMachine* sm) {return true; });
    //sm->addTransition(s3, s4, [](aStateMachine* sm) {return true; });
    //sm->addTransition(s4, 0,  [](aStateMachine* sm) {return true; });
    //sm->showStates();

    //sm->start(s1);

    ////update �����״̬��״̬����ִ��excution Ȼ���ж�condtion
    //sm->update();
    //sm->update();
    //sm->update();
    //sm->update();
    //sm->update();

}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
