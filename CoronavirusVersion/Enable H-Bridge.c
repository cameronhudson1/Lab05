Enable H-Bridge
    EN_A: Port: <x> Pin: <n> 
    EN_B: Port: <x> Pin: <n>
    SCGC: <n>
    
    // Write code to initialize GPIO and set output high
    
DC Motor Signals
    GPIO Port and Pins
    A1: Port: <x> Pin: <n> AltFn: <n>
    A2: Port: <x> Pin: <n> AltFn: <n>
    B1: Port: <x> Pin: <n> AltFn: <n>
    B2: Port: <x> Pin: <n> AltFn: <n>
    
    FTM: <n>
    FTM Channels: <n>, <n>, <n>, <n>
    
    Fill in FTM registers (pseudo code works):
    MOD: <n>
    Status Control
        Clock Source: FTM_SC_PS(<n>)
        Clock Source: FTM_SC_CLKS(<n>)
        
    // Write pseudo code to set duty cycle and direction
    // CHECK TEMPLATE CODE FOR HINTS
        
        
Servo Signals
    GPIO Port and Pins
    Sig: Port: <x> Pin: <n> AltFn: <n>
    
    FTM: <n>
    FTM Channel: <n>
    
    Fill in FTM registers (pseudo code works):
    - Note: Watch carefully how large your registers are and what size value
            they can hold
    MOD: <n>
    Status Control
        Clock Source: FTM_SC_PS(<n>)
        Clock Source: FTM_SC_CLKS(<n>)
        
    // Write pseudo code to set duty cycle, ensure a valid duty cycle
    // Start with template code