# STM32 GPIO and External Interrupts

## Hardware Used

- STM32F401RE Nucleo Board

## Projects Included

### 1. LED_ON_OFF

Turn the onboard LD2 LED ON and OFF using GPIO register programming.

#### Flow Diagram

```text
Configure PA5 as Output
        ↓
Set PA5 High
        ↓
LED ON
        ↓
Set PA5 Low
        ↓
LED OFF
```

---

### 2. BUTTON_LED_CONTROL

Control the onboard LD2 LED using the user push button (PC13).

#### Flow Diagram

```text
Read PC13
        ↓
Button Pressed?
      ↙     ↘
    Yes      No
     ↓        ↓
  LED ON   LED OFF
```

---

### 3. GPIO_EXTI_PC13

Generate an external interrupt using the onboard user button (PC13) and toggle LD2.

#### Flow Diagram

```text
System Start
      │
      ▼
Initialize UART
      │
      ▼
Configure PC13 as EXTI Source
      │
      ▼
Enable EXTI13 Interrupt in NVIC
      │
      ▼
Main Loop Running
      │
      ├────► Print "Normal..."
      │
      ▼
User Presses PC13 Button
      │
      ▼
EXTI13 Interrupt Generated
      │
      ▼
EXTI15_10_IRQHandler()
      │
      ▼
Clear Pending Flag
      │
      ▼
Toggle LD2 (PA5)
      │
      ▼
Print "Interrupt Occured..."
      │
      ▼
Return to Main Loop
```

#### Output

Output screenshot is available in:

```text
GPIO_EXTI_PC13/Output.png
```


## Concepts Learned

- GPIO Configuration
- GPIO Input and Output
- External Interrupts (EXTI)
- NVIC
- Interrupt Service Routines (ISR)
- UART Debugging
- Register-Level Programming
