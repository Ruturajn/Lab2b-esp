# PIO SEQUENCER

The following demonstration video shows the sequencer implemented with the PIO module.

https://user-images.githubusercontent.com/56625259/202370618-72c93ca5-7e69-40b5-bf24-98da307a8e60.mp4

- This code utilizes the PIO module to monitor the `BOOT` button presses.
- The `.pio` assembly file was updated to poll the `BOOT` pin (`GPIO21`) of the RP2040.
- Here, the `in` directive in the `pio` assembly language was used to shift the value read from the `BOOT` pin into the `ISR`.
- Once, the value was written to the `ISR`, it needed to be pushed to the `RX FIFO` of the `SM`.
- This was done by enabling the `autopush` functionality with a very low threshold, since we only needed to read the value for a single pin.
- After the data was pushed into the `RX FIFO`, the `pio_sm_get` function (defined in the SDK) was used in the `C` code to access the data read from the pin.
- Based on this data, the recording was created.
- The process for recording and replaying the data is similar to the one explained in [`part_03 - sequencer_host_keys_macros`](https://github.com/Ruturajn/Lab2b-esp/tree/main/lab2b_parts/03_sequencer/sequencer_host_keys_macros).
- Note that the python serial library was also used here, for storing the recorded sequence on to the host, and then reading it to replay the sequence on the `RP2040`.
- The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
- Also, following is a screenshot of the recorded sequence that was stored in the text file on the host,

![image](https://user-images.githubusercontent.com/56625259/202372417-ec9e87c0-d9fd-4b6c-874f-7b9ee2a95da3.png)
