# ADAS-with-V2V-Communication

Goal of this project is to broadcast the vehicle ADAS data such as speed and engine revolution per minute while vehicle on the road.
Project collect ADAS data reading OBD II port with Texas Instruments Hercules TMS57012 card from vehicle. Simultaneously the ADAS data streaming through Texas Instruments CC3200 Wi-Fi card to Local Area Network. TMS57012 card is preferred because it has 2 CAN bus and 2 UART interface that very compatible for OBD II. CC3200 card preferred because it has onboard Wi-Fi and UART. Project aims for reduce pileup accident and traffic jam while broadcasting vehicle data to V2I, V2V and V2X. 
