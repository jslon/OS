global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

global loadIDT

extern reg_idts
extern printCh
extern printStr

extern interrupt_0
extern interrupt_1
extern interrupt_2
extern interrupt_3
extern interrupt_4
extern interrupt_5
extern interrupt_6
extern interrupt_7
extern interrupt_8
extern interrupt_9
extern interrupt_10
extern interrupt_11
extern interrupt_12
extern interrupt_13
extern interrupt_14
extern interrupt_15
extern interrupt_16
extern interrupt_17
extern interrupt_18
extern interrupt_19
extern interrupt_20
extern interrupt_21
extern interrupt_22
extern interrupt_23
extern interrupt_24
extern interrupt_25
extern interrupt_26
extern interrupt_27
extern interrupt_28
extern interrupt_29
extern interrupt_30
extern interrupt_31
extern interrupt_32
extern interrupt_33
extern interrupt_34
extern interrupt_35
extern interrupt_36
extern interrupt_37
extern interrupt_38
extern interrupt_39
extern interrupt_40
extern interrupt_41
extern interrupt_42
extern interrupt_43
extern interrupt_44
extern interrupt_45
extern interrupt_46
extern interrupt_47

loadIDT:
lidt [ reg_idts]
ret

;ISR's (Interrupt Service Routine) 0-31

isr0:
     cld
     cli
     
     call interrupt_0

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr1:
     cld
     cli
     
     call interrupt_1

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr2:
     cld
     cli
     
     call interrupt_2

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr3:
     cld
     cli
     
     call interrupt_3

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr4:
     cld
     cli
     
     call interrupt_4

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr5:
     cld
     cli
     
     call interrupt_5

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr6:
     cld
     cli
     
     call interrupt_6

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr7:
     cld
     cli
     
     call interrupt_7

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr8:
     cld
     cli
     
     call interrupt_8

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr9:
     cld
     cli
     
     call interrupt_9

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr10:
     cld
     cli
     
     call interrupt_10

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr11:
     cld
     cli
     
     call interrupt_11

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr12:
     cld
     cli
     
     call interrupt_12

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr13:
     cld
     cli
     
     call interrupt_13

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr14:
     cld
     cli
     
     call interrupt_14

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr15:
     cld
     cli
     
     call interrupt_15

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr16:
     cld
     cli
     
     call interrupt_16

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr17:
     cld
     cli
     
     call interrupt_17

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr18:
     cld
     cli
     
     call interrupt_18

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr19:
     cld
     cli
     
     call interrupt_19

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr20:
     cld
     cli
     
     call interrupt_20

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr21:
     cld
     cli
     
     call interrupt_21

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr22:
     cld
     cli
     
     call interrupt_22

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr23:
     cld
     cli
     
     call interrupt_23

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr24:
     cld
     cli
     
     call interrupt_24

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr25:
     cld
     cli
     
     call interrupt_25

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr26:
     cld
     cli
     
     call interrupt_26

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr27:
     cld
     cli
     
     call interrupt_27

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr28:
     cld
     cli
     
     call interrupt_28

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr29:
     cld
     cli
     
     call interrupt_29

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr30:
     cld
     cli
     
     call interrupt_30

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret
isr31:
     cld
     cli
     
     call interrupt_31

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iret


;;-----------------------------------------------------------

;; IRQ's (Interrupt Requests) 32-47

            ;interrupcion del temporizador
irq0:       ;32
     cld
     cli
        
     call interrupt_32

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iretd


            ;interrupcion del teclado
irq1:       ;33
     cld
     cli

     call interrupt_33

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al
     iretd

irq2:      ;34
     cld
     cli
     
     call interrupt_34


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq3:      ;35
     cld
     cli
     
     call interrupt_35


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq4:      ;36
     cld
     cli
     
     call interrupt_36


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq5:      ;37
     cld
     cli
     
     call interrupt_37

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq6:      ;38
     cld
     cli
     
     call interrupt_38


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq7:      ;39
     cld
     cli
     
     call interrupt_39


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq8:      ;40
     cld
     cli
     
     call interrupt_40


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq9:      ;41
     cld
     cli
     
     call interrupt_41


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq10:      ;42
     cld
     cli
     
     call interrupt_42


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq11:      ;43
     cld
     cli

     call interrupt_43


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq12:      ;44
     cld
     cli
     
     call interrupt_44


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq13:      ;45
     cld
     cli
     
     call interrupt_45


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq14:      ;46
     cld
     cli
     
     call interrupt_46


     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
irq15:      ;47
     cld
     cli
     
     call interrupt_47

     sti
     mov al,0x20    ;permite futuras interrupciones
     out 0x20,al

     iretd
