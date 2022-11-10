# SLOW MOTION

This demonstration video shows, a sequence of `BOOT` button keypresses on the RP2040, recorded to the host (laptop) on a text file, and played on the `neopixel` LED,
by reading the file stored on the host. This operation is achieved by encoding ***macros*** to do tasks like recording a sequence (to the host) or playing
it (on the RP2040) in ***fast-forward*** or ***slow motion*** mode.

- The process here is very similar to the one implemented in [`sequencer_host_keys_macros`](https://github.com/Ruturajn/Lab2b-esp/tree/main/lab2b_parts/03_sequencer/sequencer_host_keys_macros)
  section of the [`03_sequencer`](https://github.com/Ruturajn/Lab2b-esp/tree/main/lab2b_parts/03_sequencer) part.
- This code just adds on some extra lines to the aforementioned code and extends it's functionality to enable the user to replay the recording in either
  ***fast-forward*** or ***slow motion*** mode.
- To achieve such behaviour, the `wait time` variable in adjusted to create a ***fast-forward*** or ***slow motion*** effect. That is, for the ***fast-forward*** mode,
  the `CONST_TIME_SCALING_FACTOR` variable by which the `wait time` is being multiplied is decreased. Whereas, for the ***slow motion*** mode, the value for 
  `CONST_TIME_SCALING_FACTOR` variable is increased.
 - By altering the `wait time` the code acheives a good emulation of replaying a sequence in ***fast-forward*** and ***slow-motion*** mode.
 - The `re_build.sh` file is a `bash` script that removes the exisiting `build` directory, and creates a new one. After that it navigates into it, and calls `cmake`,
  followed by `make`. This is a convinience script written to automate the build process.
 - Also, following is a screenshot of the recorded sequence that was stored in the text file on the host,

![image](https://user-images.githubusercontent.com/56625259/200971580-48031db7-ba72-449a-a11d-cb79f631750f.png)
