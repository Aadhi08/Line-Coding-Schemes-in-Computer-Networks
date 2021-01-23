## Line coding schemes in Computer Networks
# THEORY
Line coding refers to the process of converting digital data into digital signals. Whenever we transmit data it is in the form of digital signals, so with the help of line coding, we can convert a sequence to bits (or encoding) into a digital signal which then again converted into bits by the receiver (or can be said as decoded by the receiver). For all this to happen we need line coding schemes which could also be able to avoid overlapping and distortion of signals.
Characteristics of line coding schemes:
1.Less complexity.
2.Should have noise and interference tolerance.
3.No DC component (or say low-frequency component) should be there because it can't be transferred to larger distances.
4.Least baseline wandering should be there (baseline wander: low-frequency noise having nonlinear and non-stationary nature).
5.Should have error detection capability.
6.Should be self-synchronized.
Three types of line coding schemes:
1.	Unipolar
2.	Polar
3.	Bipolar

In Unipolar we are representing a signal in a graphical form where positive voltage represents logical or binary 1 and zero voltage represents logical zero. We can say that it's the simplest line code. The drawback of this scheme is that it is not self-clocking which means that it can't be decoded without a separate clock signal or any other synchronization source. There should be no DC component present which it significantly contains, which can be halved by returning to zero in the middle of the bit period.

The term Non-Return to Zero (NRZ) means that the signal (the red line in the above diagram) will not return to zero in middle of the bit (i.e. either 0 or 1). Unipolar schemes were generally designed as NRZ schemes. But if we compare it to the polar NRZ scheme, this scheme leads to wastage of power i.e. the normalized power (i.e. the power required to send 1-bit per resistance) is almost double as compared to polar NRZ.

Return to zero proved out to be a nice alternative or say a solution to NRZ drawbacks. Unlike NRZ, RZ uses three values of voltage i.e. positive, negative, zero. And as the name suggests it returns to zero in the middle of each bit.

We can say that Manchester encoding is a combination of RZ and NRZ-L. here, instead of using three values of voltages we use only two, here logical 1 is represented in two halves, the first half consists of a negative voltage and the second-half is represented as positive voltage, and logical 0 is also represented in two halves, the first half consists of a positive voltage and the second-half is represented as negative voltage. The transition in the middle of the bit provides synchronization.

# About The code
The code is entirely built using C programming language using various looping structures from scratch providing for any kind of 8 bit value the various schemes encoded output will be shown.
This was an assignment for us and we decided to make out our own code from it resulting in such a exclusive code with just logics and loopings/decision statements.
