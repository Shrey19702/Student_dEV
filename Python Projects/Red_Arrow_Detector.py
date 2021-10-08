import cv2
import numpy as np

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)                                    # accessing webcam


def nothing(x):                                                             # creating empty function
    pass


cv2.namedWindow("Trackbars")                                                # creating window named "Trackbar"
cv2.createTrackbar("L_H", "Trackbars", 110, 179, nothing)                   # creating trackbars and setting their range
cv2.createTrackbar("L_S", "Trackbars", 100, 255, nothing)
cv2.createTrackbar("L_V", "Trackbars", 90, 255, nothing)
cv2.createTrackbar("U_H", "Trackbars", 179, 179, nothing)
cv2.createTrackbar("U_S", "Trackbars", 255, 255, nothing)
cv2.createTrackbar("U_V", "Trackbars", 255, 255, nothing)

if (cap.isOpened() == False):                                               # checking if webcam is successfully accessed or not
    print('Error while trying to open video. Please check again...')


while True:
    _, frame = cap.read()                                                   # capturing frame and reading it

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)                            # converting captured frame  to HSV from RGB

    l_h = cv2.getTrackbarPos("L_H", "Trackbars")                            # specifying trackbar parameters
    l_s = cv2.getTrackbarPos("L_S", "Trackbars")
    l_v = cv2.getTrackbarPos("L_V", "Trackbars")
    h_h = cv2.getTrackbarPos("U_H", "Trackbars")
    h_s = cv2.getTrackbarPos("U_S", "Trackbars")
    h_v = cv2.getTrackbarPos("U_V", "Trackbars")

    lower_red = np.array([l_h, l_s, l_v])
    upper_red = np.array([h_h, h_s, h_v])

    mask = cv2.inRange(hsv, lower_red, upper_red)                            # masking
    kernel = np.ones((4, 4), np.uint8)                                       # creating kernels to remove noises
    mask = cv2.erode(mask, kernel)                                           # Eroding the mask
    mask = cv2.dilate(mask, kernel)                                          # Dilating the mask
    res = cv2.bitwise_and(frame, frame, mask=mask)                           # applying bitwise operator


    contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)    # contours detection

    for cnt in contours:
        area = cv2.contourArea(cnt)
        approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)       # Contour approxiamation
        x = approx.ravel()[0]
        y = approx.ravel()[1]


        x, y, w, h = cv2.boundingRect(cnt)                                          # Obtain bounding box coordinates and draw rectangle
        cv2.rectangle(frame, (x, y), (x + w, y + h), (36, 255, 12), 2)
        m1, n1 = (int((2 * x + w) / 2), y)
        m2, n2 = (int((2 * x + w) / 2), y + h)

        if area > 1000:                                                             # specifying the area of object below which no contour is made


            if len(approx) == 4:
                cv2.putText(frame, "Rectangle", (x, y), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0),2)   # Inserting text into frame
                cv2.putText(res, "Rectangle", (x, y), cv2.FONT_HERSHEY_TRIPLEX, 1, (200, 150, 0), 2)

            if len(approx)==7:
                extLeft = tuple(approx[approx[:, :, 0].argmin()][0])
                extRight = tuple(approx[approx[:, :, 0].argmax()][0])
                extTop = tuple(approx[approx[:, :, 1].argmin()][0])
                extBot = tuple(approx[approx[:, :, 1].argmax()][0])
                cv2.line(frame, extLeft, extRight, (0,255,0),3)
                cv2.putText(frame, "Arrow", (x, y), cv2.FONT_HERSHEY_COMPLEX, 2, (0, 0, 0), 3)
                cv2.putText(res, "Arrow", (x, y), cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 255, 0), 3)
                cv2.line(frame, (m1, n1), (m2, n2), (0, 255, 0), 3, cv2.FILLED)
                cv2.line(res, (m1, n1), (m2, n2), (0, 255, 0), 3, cv2.FILLED)
                cv2.drawContours(frame, [approx], -1, (0, 255, 255), 2)
                cv2.circle(frame, extLeft, 8, (0, 0, 255), -1)
                cv2.circle(frame, extRight, 8, (0, 255, 0), -1)
                cv2.circle(frame, extTop, 8, (255, 0, 0), -1)
                cv2.circle(frame, extBot, 8, (255, 255, 0), -1)


    cv2.imshow("Frame", frame)                                                  # showing raw webcam image
    cv2.imshow("Mask", mask)                                                    # displaying masked image
    cv2.imshow("res", res)                                                      # displaying bitwise operated image

    key = cv2.waitKey(1)                                                        # frame delay(1ms) specified as argument
    if key == 27:                                                               # specifying when to stop executing the code
        break

cap.release()
cv2.destroyAllWindows()