import cv2
import serial
import time

# CHANGE THIS TO YOUR PORT (check in Arduino IDE > Tools > Port)
arduino = serial.Serial('COM7', 9600)
time.sleep(2)  # Give Arduino time to reset

cap = cv2.VideoCapture(0)  # Default webcam

# Load face detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

while True:
    ret, frame = cap.read()
    if not ret:
        continue

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)

    if len(faces) == 0:
        print("✅ Helmet worn")
        arduino.write(b'1')  # No face = helmet
    else:
        print("❌ No helmet!")
        arduino.write(b'0')  # Face seen = no helmet

    cv2.imshow("Helmet Detection", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
