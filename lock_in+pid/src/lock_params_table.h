#ifndef __LOCK_PARAMS_TABLE_H
#define __LOCK_PARAMS_TABLE_H

#define LOCK_PARAMS_DEFAULTS \
    { "lock_oscA_sw"                  ,      1, 1, 0,            0,           31 }, /** switch for muxer oscA **/ \
    { "lock_oscB_sw"                  ,      2, 1, 0,            0,           31 }, /** switch for muxer oscB **/ \
    { "lock_osc1_filt_off"            ,      1, 1, 0,            0,            1 }, /** oscilloscope control osc1_filt_off **/ \
    { "lock_osc2_filt_off"            ,      1, 1, 0,            0,            1 }, /** oscilloscope control osc2_filt_off **/ \
    { "lock_osc_raw_mode"             ,      0, 0, 0,            0,            1 }, /** Set oscilloscope mode in Raw (int unit instead of Volts) **/ \
    { "lock_osc_lockin_mode"          ,      0, 0, 0,            0,            1 }, /** Set oscilloscope mode in lock-in (ch1 as R [V|int], ch2 as Phase [rad]) **/ \
    { "lock_trig_sw"                  ,      0, 1, 0,            0,          255 }, /** Select the external trigger signal **/ \
    { "lock_out1_sw"                  ,      0, 1, 0,            0,           15 }, /** switch for muxer out1 **/ \
    { "lock_out2_sw"                  ,      0, 1, 0,            0,           15 }, /** switch for muxer out2 **/ \
    { "lock_slow_out1_sw"             ,      0, 1, 0,            0,           15 }, /** switch for muxer slow_out1 **/ \
    { "lock_slow_out2_sw"             ,      0, 1, 0,            0,           15 }, /** switch for muxer slow_out2 **/ \
    { "lock_slow_out3_sw"             ,      0, 1, 0,            0,           15 }, /** switch for muxer slow_out3 **/ \
    { "lock_slow_out4_sw"             ,      0, 1, 0,            0,           15 }, /** switch for muxer slow_out4 **/ \
    { "lock_lock_control"             ,   1148, 1, 0,            0,         2047 }, /** lock_control help **/ \
    { "lock_lock_feedback"            ,   1148, 0, 1,            0,         2047 }, /** lock_control feedback **/ \
    { "lock_lock_trig_val"            ,      0, 1, 0,        -8192,         8191 }, /** if lock_control ?? , this vals sets the voltage threshold that turns on the lock **/ \
    { "lock_lock_trig_time_val"       ,      0, 1, 0,            0,   0xffffffff }, /** if lock_control ?? , this vals sets the time threshold that turns on the lock **/ \
    { "lock_lock_trig_sw"             ,      0, 1, 0,            0,           15 }, /** selects signal for trigger **/ \
    { "lock_rl_error_threshold"       ,      0, 1, 0,            0,         8191 }, /** Threshold for error signal. Launchs relock when |error| > rl_error_threshold **/ \
    { "lock_rl_signal_sw"             ,      0, 1, 0,            0,            7 }, /** selects signal for relock trigger **/ \
    { "lock_rl_signal_threshold"      ,      0, 1, 0,        -8192,         8191 }, /** Threshold for signal. Launchs relock when signal < rl_signal_threshold **/ \
    { "lock_rl_error_enable"          ,      0, 1, 0,            0,            1 }, /** Relock enable. [enable_error_th]  **/ \
    { "lock_rl_signal_enable"         ,      0, 1, 0,            0,            1 }, /** Relock enable. [enable_signal_th]  **/ \
    { "lock_rl_reset"                 ,      0, 1, 0,            0,            1 }, /** Relock enable. [relock_reset]  **/ \
    { "lock_rl_state"                 ,      0, 0, 1,            0,           31 }, /** Relock state: [state:idle|searching|failed,signal_fail,error_fail,locked]  **/ \
    { "lock_sf_jumpA"                 ,      0, 1, 0,        -8192,         8191 }, /** Step function measure jump value for ctrl_A **/ \
    { "lock_sf_jumpB"                 ,      0, 1, 0,        -8192,         8191 }, /** Step function measure jump value for ctrl_B **/ \
    { "lock_sf_start"                 ,      0, 1, 0,            0,            1 }, /** Step function start  **/ \
    { "lock_sf_AfrzO"                 ,      0, 1, 0,            0,            1 }, /** Step function pidA_freeze  **/ \
    { "lock_sf_AfrzI"                 ,      0, 1, 0,            0,            1 }, /** Step function pidA_ifreeze  **/ \
    { "lock_sf_BfrzO"                 ,      0, 1, 0,            0,            1 }, /** Step function pidB_freeze  **/ \
    { "lock_sf_BfrzI"                 ,      0, 1, 0,            0,            1 }, /** Step function pidB_ifreeze  **/ \
    { "lock_signal_sw"                ,      0, 1, 0,            0,           15 }, /** Input selector for signal_i **/ \
    { "lock_signal_i"                 ,      0, 0, 1,        -8192,         8191 }, /** signal for demodulation **/ \
    { "lock_sg_amp1"                  ,      0, 1, 0,            0,           15 }, /** amplification of Xo, Yo and F1o **/ \
    { "lock_sg_amp2"                  ,      0, 1, 0,            0,           15 }, /** amplification of F2o **/ \
    { "lock_sg_amp3"                  ,      0, 1, 0,            0,           15 }, /** amplification of F3o **/ \
    { "lock_sg_amp_sq"                ,      0, 1, 0,            0,           15 }, /** amplification of SQo **/ \
    { "lock_lpf_F1_tau"               ,      0, 1, 0,            0,           15 }, /** Low Pass Filter TAU of X, Y and F1 **/ \
    { "lock_lpf_F1_order"             ,      2, 1, 0,            0,            2 }, /** Low Pass Filter order / off **/ \
    { "lock_lpf_F2_tau"               ,      0, 1, 0,            0,           15 }, /** Low Pass Filter TAU of F2 **/ \
    { "lock_lpf_F2_order"             ,      2, 1, 0,            0,            2 }, /** Low Pass Filter order / off **/ \
    { "lock_lpf_F3_tau"               ,      0, 1, 0,            0,           15 }, /** Low Pass Filter TAU of F3 **/ \
    { "lock_lpf_F3_order"             ,      2, 1, 0,            0,            2 }, /** Low Pass Filter order / off **/ \
    { "lock_lpf_sq_tau"               ,      0, 1, 0,            0,           15 }, /** Low Pass Filter TAU of Square **/ \
    { "lock_lpf_sq_order"             ,      2, 1, 0,            0,            2 }, /** Low Pass Filter order / off **/ \
    { "lock_error_sw"                 ,      0, 1, 0,            0,            7 }, /** select error signal **/ \
    { "lock_error_offset"             ,      0, 1, 0,        -8192,         8191 }, /** offset for the error signal **/ \
    { "lock_error"                    ,      0, 0, 1,        -8192,         8191 }, /** error signal value **/ \
    { "lock_error_mean"               ,      0, 0, 1,  -0x80000000,   0x7fffffff }, /** 1 sec error mean val **/ \
    { "lock_error_std"                ,      0, 0, 1,  -0x80000000,   0x7fffffff }, /** 1 sec error square sum val **/ \
    { "lock_gen_mod_phase"            ,      0, 1, 0,            0,         2519 }, /** phase relation of cos_?f signals **/ \
    { "lock_gen_mod_phase_sq"         ,      0, 1, 0,            0,   0xffffffff }, /** phase relation of sq_phas signal **/ \
    { "lock_gen_mod_hp"               ,      0, 1, 0,            0,        16383 }, /** harmonic period set **/ \
    { "lock_gen_mod_sqp"              ,      0, 1, 0,            0,   0xffffffff }, /** square signal period **/ \
    { "lock_ramp_A"                   ,      0, 0, 1,        -8192,         8191 }, /** ramp signal A **/ \
    { "lock_ramp_B"                   ,      0, 0, 1,        -8192,         8191 }, /** ramp signal B **/ \
    { "lock_ramp_step"                ,      0, 1, 0,            0,   0xffffffff }, /** period of the triangular ramp signal **/ \
    { "lock_ramp_low_lim"             ,  -5000, 1, 0,        -8192,         8191 }, /** ramp low limit **/ \
    { "lock_ramp_hig_lim"             ,   5000, 1, 0,        -8192,         8191 }, /** ramp high limit **/ \
    { "lock_ramp_reset"               ,      0, 1, 0,            0,            1 }, /** ramp reset config **/ \
    { "lock_ramp_enable"              ,      0, 1, 0,            0,            1 }, /** ramp enable/disable switch **/ \
    { "lock_ramp_direction"           ,      0, 1, 0,            0,            1 }, /** ramp starting direction (up/down) **/ \
    { "lock_ramp_B_factor"            ,   4096, 1, 0,        -4096,         4096 }, /** proportional factor ramp_A/ramp_B. // ramp_B=ramp_A*ramp_B_factor/4096 **/ \
    { "lock_sin_ref"                  ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation sinus harmonic reference **/ \
    { "lock_cos_ref"                  ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation cosinus harmonic reference **/ \
    { "lock_cos_1f"                   ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation sinus harmonic signal with phase relation to reference **/ \
    { "lock_cos_2f"                   ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation sinus harmonic signal with phase relation to reference and double frequency **/ \
    { "lock_cos_3f"                   ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation sinus harmonic signal with phase relation to reference and triple frequency **/ \
    { "lock_sq_ref_b"                 ,      0, 0, 1,            0,            1 }, /** lock-in modulation binary reference **/ \
    { "lock_sq_quad_b"                ,      0, 0, 1,            0,            1 }, /** lock-in modulation binary quadrature **/ \
    { "lock_sq_phas_b"                ,      0, 0, 1,            0,            1 }, /** lock-in modulation binary with phase respect to reference **/ \
    { "lock_sq_ref"                   ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation square signal reference **/ \
    { "lock_sq_quad"                  ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation square signal quadrature **/ \
    { "lock_sq_phas"                  ,      0, 0, 1,        -8192,         8191 }, /** lock-in modulation square signal with phase relation to reference **/ \
    { "lock_in1"                      ,      0, 0, 1,        -8192,         8191 }, /** Input signal IN1 **/ \
    { "lock_in2"                      ,      0, 0, 1,        -8192,         8191 }, /** Input signal IN2 **/ \
    { "lock_out1"                     ,      0, 0, 1,        -8192,         8191 }, /** signal for RP RF DAC Out1 **/ \
    { "lock_out2"                     ,      0, 0, 1,        -8192,         8191 }, /** signal for RP RF DAC Out2 **/ \
    { "lock_slow_out1"                ,      0, 0, 1,        -2048,         2047 }, /** signal for RP slow DAC 1 **/ \
    { "lock_slow_out2"                ,      0, 0, 1,        -2048,         2047 }, /** signal for RP slow DAC 2 **/ \
    { "lock_slow_out3"                ,      0, 0, 1,        -2048,         2047 }, /** signal for RP slow DAC 3 **/ \
    { "lock_slow_out4"                ,      0, 0, 1,        -2048,         2047 }, /** signal for RP slow DAC 4 **/ \
    { "lock_oscA"                     ,      0, 0, 1,        -8192,         8191 }, /** signal for Oscilloscope Channel A **/ \
    { "lock_oscB"                     ,      0, 0, 1,        -8192,         8191 }, /** signal for Oscilloscope Channel B **/ \
    { "lock_X"                        ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from sin_ref **/ \
    { "lock_Y"                        ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from cos_ref **/ \
    { "lock_F1"                       ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from cos_1f **/ \
    { "lock_F2"                       ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from cos_2f **/ \
    { "lock_F3"                       ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from cos_3f **/ \
    { "lock_sqX"                      ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from sq_ref **/ \
    { "lock_sqY"                      ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from sq_quad **/ \
    { "lock_sqF"                      ,      0, 0, 1,   -134217728,    134217727 }, /** Demodulated signal from sq_phas **/ \
    { "lock_cnt_clk"                  ,      0, 0, 1,            0,   0xffffffff }, /** Clock count **/ \
    { "lock_cnt_clk2"                 ,      0, 0, 1,            0,   0xffffffff }, /** Clock count **/ \
    { "lock_read_ctrl"                ,      0, 1, 0,            0,            7 }, /** [unused,start_clk,Freeze] **/ \
    { "lock_pidA_sw"                  ,      0, 1, 0,            0,           31 }, /** switch selector for pidA input **/ \
    { "lock_pidA_PSR"                 ,      3, 1, 0,            0,            4 }, /** pidA PSR **/ \
    { "lock_pidA_ISR"                 ,      8, 1, 0,            0,            9 }, /** pidA ISR **/ \
    { "lock_pidA_DSR"                 ,      0, 1, 0,            0,            5 }, /** pidA DSR **/ \
    { "lock_pidA_SAT"                 ,     13, 1, 0,            0,           13 }, /** pidA saturation control **/ \
    { "lock_pidA_sp"                  ,      0, 1, 0,        -8192,         8191 }, /** pidA set_point **/ \
    { "lock_pidA_kp"                  ,      0, 1, 0,        -8192,         8191 }, /** pidA proportional constant **/ \
    { "lock_pidA_ki"                  ,      0, 1, 0,        -8192,         8191 }, /** pidA integral constant **/ \
    { "lock_pidA_kd"                  ,      0, 1, 0,        -8192,         8191 }, /** pidA derivative constant **/ \
    { "lock_pidA_in"                  ,      0, 0, 1,        -8192,         8191 }, /** pidA input **/ \
    { "lock_pidA_out"                 ,      0, 0, 1,        -8192,         8191 }, /** pidA output **/ \
    { "lock_pidA_irst"                ,      0, 1, 0,            0,            1 }, /** pidA_irst **/ \
    { "lock_pidA_freeze"              ,      0, 1, 0,            0,            1 }, /** pidA_freeze **/ \
    { "lock_pidA_ifreeze"             ,      0, 1, 0,            0,            1 }, /** pidA_ifreeze **/ \
    { "lock_ctrl_A"                   ,      0, 0, 1,        -8192,         8191 }, /** control_A: pidA_out + ramp_A **/ \
    { "lock_pidB_sw"                  ,      0, 1, 0,            0,           31 }, /** switch selector for pidB input **/ \
    { "lock_pidB_PSR"                 ,      3, 1, 0,            0,            4 }, /** pidB PSR **/ \
    { "lock_pidB_ISR"                 ,      8, 1, 0,            0,            9 }, /** pidB ISR **/ \
    { "lock_pidB_DSR"                 ,      0, 1, 0,            0,            5 }, /** pidB DSR **/ \
    { "lock_pidB_SAT"                 ,     13, 1, 0,            0,           13 }, /** pidB saturation control **/ \
    { "lock_pidB_sp"                  ,      0, 1, 0,        -8192,         8191 }, /** pidB set_point **/ \
    { "lock_pidB_kp"                  ,      0, 1, 0,        -8192,         8191 }, /** pidB proportional constant **/ \
    { "lock_pidB_ki"                  ,      0, 1, 0,        -8192,         8191 }, /** pidB integral constant **/ \
    { "lock_pidB_kd"                  ,      0, 1, 0,        -8192,         8191 }, /** pidB derivative constant **/ \
    { "lock_pidB_in"                  ,      0, 0, 1,        -8192,         8191 }, /** pidB input **/ \
    { "lock_pidB_out"                 ,      0, 0, 1,        -8192,         8191 }, /** pidB output **/ \
    { "lock_pidB_irst"                ,      0, 1, 0,            0,            1 }, /** pidB_irst **/ \
    { "lock_pidB_freeze"              ,      0, 1, 0,            0,            1 }, /** pidB_freeze **/ \
    { "lock_pidB_ifreeze"             ,      0, 1, 0,            0,            1 }, /** pidB_ifreeze **/ \
    { "lock_ctrl_B"                   ,      0, 0, 1,        -8192,         8191 }, /** control_B: pidA_out + ramp_B **/ \
    { "lock_aux_A"                    ,      0, 1, 0,        -8192,         8191 }, /** auxiliar value of 14 bits **/ \
    { "lock_aux_B"                    ,      0, 1, 0,        -8192,         8191 }, /** auxiliar value of 14 bits **/ \
    { "lock_ctrl_aux_lock_now"        ,      0, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_launch_lock_trig",      0, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_pidB_enable_ctrl",      1, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_pidA_enable_ctrl",      1, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_ramp_enable_ctrl",      1, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_set_pidB_enable" ,      1, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_set_pidA_enable" ,      1, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_set_ramp_enable" ,      0, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_ctrl_aux_trig_type"       ,      0, 0, 0,            0,            3 }, /** todo **/ \
    { "lock_ctrl_aux_lock_trig_rise"  ,      0, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_mod_sq_on"                ,      0, 0, 0,            0,            1 }, /** todo **/ \
    { "lock_mod_harmonic_on"          ,      1, 0, 0,            0,            1 }, /** todo **/ \

#endif /* __LOCK_PARAMS_TABLE_H */
