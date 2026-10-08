// defines pins numbers
const int trigPin = 11;
const int echoPin = 12;

// defines variables
long duration;
int distance;
bool objectPresent = false;
void setup() {
  // UltraSonoc Pins
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // --------------------------------------------------------
  // ADD Your Code Here - Detect a specific distance... like distance > 5 cm
   
  if (distance <= 10 && objectPresent == false)
    Serial.println("Object Detected & Present");
    objectPresent = true;
  

  if (distance > 10 && objectPresent == true) 
    Serial.println("Detected Object Is Gone");
    objectPresent = false;
  

  if (objectPresent == false) 
    Serial.println("Waiting To Detect An Object");
  

  delay(100);
}