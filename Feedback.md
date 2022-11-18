# Feedback - LAB2B

- Which parts of the lab *specification* have you found most confusing or difficult to understand? Be specific, and quote any parts
  of the lab description relevant to your answer (e.g., "modify the PIO/DMA logic analyzer example to record a timestamped trace
  of an RP2040-ADPS9960 exchange while the BOOT button is pressed.") I will make particular notice of anything that seems *underspecified*
  (e.g., words whose meaning is not clear from context, or conflicting interpretations of a deliverable).
  
  ***Ans***: I found the description for part `09_lab_on_chip` to be unclear in terms of the exact deliverables. Especially the part that said 
  "*Add APDS9960 support to your sensor, then set your system up to capture the following timing info:...*" was a bit vague, and did not provide
  us with enough information regarding the expectation for that part. Secondly, the description for part `08_apds_protocol` which read,
  "*...to implement the ADPS9960 protocol and control the sensor.*" was also confusing.
  
- Which lab topics have you found most confusing or difficult to understand? E.g., "serial communication with Python," "aliased bitwise operations,"
  "programming the PIO," etc. Be specific, and describe any lingering areas of confusion and/or anything that has helped you navigate them.
  
  ***Ans***: "*Serial Communication with Python*" was a bit confusing at first but after some time of analysing the problem, it became a bit clear.
  Apart from this, when we were asked to program the "*PIO*" module in `pio assembly` language, it created a lot of confusion and anxiety.

- Which parts of the lab have you found most difficult to implement? Again, be specific, citing any parts of the lab materials & your own code
  that are relevant to your answer.

  ***Ans***: In my opinion part `09_lab_on_chip` is the most difficult part, followed closely by part `08_apds_protocol`. This is due to the fact
  that a clear understanding regarding the objective was not provided. Integrating things like recording transitions from the `I2C` trace, and utilizing
  the `DMA` peripheral pose a problem, because achieving this requires a good understanding of not only the `I2C` protocol or the `APDS9960` sensor, but
  alse the `DMA` peripheral.
  
- What steps have you taken to resolve these difficulties? Any other barriers you have faced to completing this assignment? Mention any students, repos,
  or other resources you have found helpful in completing the lab so far.

  ***Ans***: I spent a lot of time trying to interface the `APDS9960` sensor with the `RP2040`, i.e. get it to send over the color data. Finally, I had
  to write a [header file](https://github.com/Ruturajn/Lab2b-esp/blob/main/lab2b_parts/08_apds_protocol/apds_registers.h) containing the register 
  definitions (obtained by reading the datasheet) and bit masks for configuring the `APDS9960` sensor correctly. This helped in clarifying the exact
  path that needed to be taken for modifying the control register, and abstracting away the hexadecimal values with macros that represented the register names
  and their bit definitions according to the datasheet.
