#ifndef __RADIO_SI446X_H__
#define __RADIO_SI446X_H__


#include <linux/types.h>  /* size_t */

#define MAX_PACKET_LENGTH 250
#define TX_THRESHOLD 0x23
#define RX_THRESHOLD 0x30
#define MAX_FIFO_SIZE 128

/*
 * FUNCTIONS
 */
//Writing and Reading func
u8 * SendCmdReceiveAnswer(int byteCountTx, int byteCountRx, u8 * in_buff,
	u8 * out_buff);
//void spi_write(int byteCountTx, const unsigned char* pData);
void spi_write_fifo(unsigned char * data, int len);
void spi_read_fifo(unsigned char * st, int len);
void fifo_reset(void);
void tx_fifo_reset(void);
//void read_frr_x(char no);    //no=a,b,c,d represent frr_a, frr_b, frr_c, frr_d
u8 read_frr_a(void);
void read_frr_b(u8 *value);

//Configure
void reset(void);
void setModem(void);
void start_tx(void);
void stop_tx(void);
void tune_tx(void);
void setFrequency(unsigned long freq); //Not in used
//void si4463_register_init(void);
void setRFParameters(void);

void Function_set_tran_property();

void clr_interrupt(void);
void clr_packet_sent_pend(void);
void clr_packet_rx_pend(void);
void clr_preamble_detect_pend(void);
//void clr_interrupt_async(void);
void clr_txfifo_almost_empty_pend(void);
void clr_rxfifo_almost_full_pend(void);

void enable_chip_irq(void);
//void enable_tx_interrupt(void);		// 使能发射中断
//void enable_rx_interrupt(void);		// 使能接收中断
void tx_start(void);
void rx_start(void);					// 开始接收
void tx_start_1B(void);
void tx_set_packet_len(u8 packetlen);

void change_state2tx_tune(void);

void set_frr_ctl(void);
//Status Getting Method
u8 get_device_state(void);
u8 get_packet_info(void);
void get_ph_status(u8 *rx);
void get_modem_status(u8 *rx);
void get_fifo_info(u8 * rx);
int get_CCA_latch(void);
bool get_CCA(void);
bool is_tx_fifo_almost_empty(void);
void get_interrupt_status(u8* p2);


//-----------------------------------------------------------------------------
// SI446X_B1_defs.h
//-----------------------------------------------------------------------------
// Copyright 2012 Silicon Laboratories, Inc.
// http://www.silabs.com
//
// Created by:
//
//	Silicon Laboratiories Inc.
//	Attila Gosi
//
// Program Description:
// 	Si446x B1 family specific definitions (commands, properties)
//
// Release 3.0
// Source: FW 3.0.7 API description

//-----------------------------------------------------------------------------
// Header File Preprocessor Directive
//-----------------------------------------------------------------------------
//#ifndef SI446X_B1_DEFS_H
//#define SI446X_B1_DEFS_H

//-----------------------------------------------------------------------------
//	Commands
//-----------------------------------------------------------------------------

// Boot Commands
#define CMD_POWER_UP						    0x02
#define CMD_PATCH_IMAGE							0x04

// Common Commands
//#define CMD_NOP_									0x00
#define CMD_PART_INFO							0x01
#define CMD_FUNC_INFO							0x10
#define CMD_SET_PROPERTY						0x11
#define CMD_GET_PROPERTY						0x12
#define CMD_GPIO_PIN_CFG						0x13
#define CMD_FIFO_INFO							0x15
#define CMD_GET_INT_STATUS					    0x20
#define CMD_REQUEST_DEVICE_STATE		        0x33
#define CMD_CHANGE_STATE						0x34
#define CMD_READ_CMD_BUFF						0x44
#define CMD_FRR_A_READ							0x50
#define CMD_FRR_B_READ							0x51
#define CMD_FRR_C_READ							0x53
#define CMD_FRR_D_READ							0x57
#define CMD_WRITE_TX_FIFO						0x66
#define CMD_READ_RX_FIFO						0x77
#define CMD_GET_ADC_READING						0x14
#define CMD_PACKET_INFO							0x16
#define CMD_IRCAL								0x17
#define CMD_PROTOCOL_CFG						0x18
#define CMD_GET_PH_STATUS						0x21
#define CMD_GET_MODEM_STATUS					0x22
#define CMD_GET_CHIP_STATUS						0x23
#define CMD_RX_HOP								0x36

// Tx Commands
#define CMD_START_TX						    0x31

// Rx Commands
#define CMD_START_RX							0x32

// Debug Commands


//-----------------------------------------------------------------------------
//   Properties
//-----------------------------------------------------------------------------

#define PROP_GLOBAL_GROUP						    0x00
#define PROP_GLOBAL_XO_TUNE			        		0x00
#define PROP_GLOBAL_CLK_CFG		        			0x01
#define PROP_GLOBAL_LOW_BATT_THRESH       			0x02
#define PROP_GLOBAL_CONFIG				        	0x03
#define PROP_GLOBAL_WUT_CONFIG        				0x04
#define PROP_GLOBAL_WUT_M_15_8	        			0x05
#define PROP_GLOBAL_WUT_M_7_0	        			0x06
#define PROP_GLOBAL_WUT_R					        0x07
#define PROP_GLOBAL_WUT_LDC				      	  	0x08
#define PROP_GLOBAL_WUT_CAL       					0x09

#define PROP_INT_CTL_GROUP			        		0x01
#define PROP_INT_CTL_ENABLE	        				0x00
#define PROP_INT_CTL_PH_ENABLE        				0x01
#define PROP_INT_CTL_MODEM_ENABLE       			0x02
#define PROP_INT_CTL_CHIP_ENABLE	        		0x03

#define PROP_FRR_CTL_GROUP			         			0x02
#define PROP_FRR_CTL_A_MODE			         			0x00
#define PROP_FRR_CTL_B_MODE			        			0x01
#define PROP_FRR_CTL_C_MODE		        				0x02
#define PROP_FRR_CTL_D_MODE		        				0x03

#define PROP_PREAMBLE_GROUP			        	0x10
#define PROP_PREAMBLE_TX_LENGTH			        0x00
#define PROP_PREAMBLE_CONFIG_STD_1	    		0x01
#define PROP_PREAMBLE_CONFIG_NSTD		      	0x02
#define PROP_PREAMBLE_CONFIG_STD_2	    		0x03
#define PROP_PREAMBLE_CONFIG				    0x04
#define PROP_PREAMBLE_PATTERN_31_24	    		0x05
#define PROP_PREAMBLE_PATTERN_23_16	    		0x06
#define PROP_PREAMBLE_PATTERN_15_8	      		0x07
#define PROP_PREAMBLE_PATTERN_7_0			    0x08
#define PROP_PREAMBLE_POSTAMBLE_CONFIG	  		0x09
#define PROP_PREAMBLE_POSTAMBLE_PATTERN_31_24	0x0A
#define PROP_PREAMBLE_POSTAMBLE_PATTERN_23_16	0x0B
#define PROP_PREAMBLE_POSTAMBLE_PATTERN_15_8	0x0C
#define PROP_PREAMBLE_POSTAMBLE_PATTERN_7_0		0x0D

#define PROP_SYNC_GROUP						    	    0x11
#define PROP_SYNC_CONFIG					    	    0x00
#define PROP_SYNC_BITS_31_24		    			    0x01
#define PROP_SYNC_BITS_23_16			    		    0x02
#define PROP_SYNC_BITS_15_8					    	    0x03
#define PROP_SYNC_BITS_7_0						        0x04

#define PROP_PKT_GROUP							    0x12
#define PROP_PKT_CRC_CONFIG					        0x00
#define PROP_PKT_WHT_POLY_15_8			    	  	0x01
#define PROP_PKT_WHT_POLY_7_0				    	0x02
#define PROP_PKT_WHT_SEED_15_8		       			0x03
#define PROP_PKT_WHT_SEED_7_0			     		0x04
#define PROP_PKT_WHT_BIT_NUM			    		0x05
#define PROP_PKT_CONFIG1					        0x06
#define PROP_PKT_RESERVED_18_7		  	       		0x07
#define PROP_PKT_LEN							    0x08
#define PROP_PKT_LEN_FIELD_SOURCE			        0x09
#define PROP_PKT_LEN_ADJUST						    0x0A
#define PROP_PKT_TX_THRESHOLD			    		0x0B
#define PROP_PKT_RX_THRESHOLD		    			0x0C
#define PROP_PKT_FIELD_1_LENGTH_12_8	    		0x0D
#define PROP_PKT_FIELD_1_LENGTH_7_0		    		0x0E
#define PROP_PKT_FIELD_1_CONFIG				    	0x0F
#define PROP_PKT_FIELD_1_CRC_CONFIG	    			0x10
#define PROP_PKT_FIELD_2_LENGTH_12_8    			0x11
#define PROP_PKT_FIELD_2_LENGTH_7_0			    	0x12
#define PROP_PKT_FIELD_2_CONFIG			    		0x13
#define PROP_PKT_FIELD_2_CRC_CONFIG		    		0x14
#define PROP_PKT_FIELD_3_LENGTH_12_8    			0x15
#define PROP_PKT_FIELD_3_LENGTH_7_0	    			0x16
#define PROP_PKT_FIELD_3_CONFIG				      	0x17
#define PROP_PKT_FIELD_3_CRC_CONFIG	    			0x18
#define PROP_PKT_FIELD_4_LENGTH_12_8    			0x19
#define PROP_PKT_FIELD_4_LENGTH_7_0			    	0x1A
#define PROP_PKT_FIELD_4_CONFIG			    		0x1B
#define PROP_PKT_FIELD_4_CRC_CONFIG			     	0x1C
#define PROP_PKT_FIELD_5_LENGTH_12_8		    	0x1D
#define PROP_PKT_FIELD_5_LENGTH_7_0			    	0x1E
#define PROP_PKT_FIELD_5_CONFIG					    0x1F
#define PROP_PKT_FIELD_5_CRC_CONFIG			    	0x20
#define PROP_PKT_RX_FIELD_1_LENGTH_12_8	    		0x21
#define PROP_PKT_RX_FIELD_1_LENGTH_7_0	  			0x22
#define PROP_PKT_RX_FIELD_1_CONFIG			    	0x23
#define PROP_PKT_RX_FIELD_1_CRC_CONFIG	  			0x24
#define PROP_PKT_RX_FIELD_2_LENGTH_12_8	  			0x25
#define PROP_PKT_RX_FIELD_2_LENGTH_7_0	  			0x26
#define PROP_PKT_RX_FIELD_2_CONFIG			     	0x27
#define PROP_PKT_RX_FIELD_2_CRC_CONFIG	  			0x28
#define PROP_PKT_RX_FIELD_3_LENGTH_12_8	  			0x29
#define PROP_PKT_RX_FIELD_3_LENGTH_7_0	  			0x2A
#define PROP_PKT_RX_FIELD_3_CONFIG			     	0x2B
#define PROP_PKT_RX_FIELD_3_CRC_CONFIG	  			0x2C
#define PROP_PKT_RX_FIELD_4_LENGTH_12_8	  			0x2D
#define PROP_PKT_RX_FIELD_4_LENGTH_7_0	  			0x2E
#define PROP_PKT_RX_FIELD_4_CONFIG		    		0x2F
#define PROP_PKT_RX_FIELD_4_CRC_CONFIG  			0x30
#define PROP_PKT_RX_FIELD_5_LENGTH_12_8	  			0x31
#define PROP_PKT_RX_FIELD_5_LENGTH_7_0	   			0x32
#define PROP_PKT_RX_FIELD_5_CONFIG		    		0x33
#define PROP_PKT_RX_FIELD_5_CRC_CONFIG  			0x34

#define PROP_MODEM_GROUP			          		0x20
#define PROP_MODEM_MOD_TYPE		        			0x00
#define PROP_MODEM_MAP_CONTROL	      				0x01
#define PROP_MODEM_DATA_RATE_2	      				0x03
#define PROP_MODEM_DATA_RATE_1	      				0x04
#define PROP_MODEM_DATA_RATE_0	      				0x05
#define PROP_MODEM_FREQ_DEV_2		        		0x0A
#define PROP_MODEM_FREQ_DEV_1		        		0x0B
#define PROP_MODEM_FREQ_DEV_0		        		0x0C
#define PROP_MODEM_FREQ_OFFSET_1      				0x0D
#define PROP_MODEM_FREQ_OFFSET_0      				0x0E
#define PROP_MODEM_AFC_GEAR			         		0x2C
#define PROP_MODEM_AFC_WAIT			        		0x2D
#define PROP_MODEM_AFC_GAIN_1		        		0x2E
#define PROP_MODEM_AFC_GAIN_0		        		0x2F
#define PROP_MODEM_AFC_LIMITER_1      				0x30
#define PROP_MODEM_AFC_LIMITER_0      				0x31
#define PROP_MODEM_AFC_MISC			        		0x32
#define PROP_MODEM_AFC_ZIFOFF		        		0x33
#define PROP_MODEM_ADC_CTRL				         	0x34
#define PROP_MODEM_FSK4_MAP 			        	0x3F
#define PROP_MODEM_ANT_DIV_CONTROL    				0x49
#define PROP_MODEM_RSSI_THRESH		      			0x4A
#define PROP_MODEM_RSSI_JUMP_THRESH			    	0x4B
#define PROP_MODEM_RSSI_CONTROL					    0x4C
#define PROP_MODEM_RSSI_CONTROL2		            0x4D
#define PROP_MODEM_RSSI_COMP					    0x4E
#define PROP_MODEM_RESERVED_20_50				    0x50

#define PROP_MODEM_CHFLT_GROUP					0x21
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE13_7_0    0x00
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE12_7_0	0x01
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE11_7_0	0x02
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE10_7_0	0x03
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE9_7_0		0x04
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE8_7_0		0x05
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE7_7_0		0x06
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE6_7_0		0x07
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE5_7_0		0x08
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE4_7_0		0x09
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE3_7_0		0x0A
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE2_7_0		0x0B
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE1_7_0		0x0C
#define PROP_MODEM_CHFLT_RX1_CHFLT_COE0_7_0		0x0D
#define PROP_MODEM_CHFLT_RX1_CHFLT_COEM0		0x0E
#define PROP_MODEM_CHFLT_RX1_CHFLT_COEM1	  	0x0F
#define PROP_MODEM_CHFLT_RX1_CHFLT_COEM2	   	0x10
#define PROP_MODEM_CHFLT_RX1_CHFLT_COEM3		0x11
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE13_7_0	0x12
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE12_7_0	0x13
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE11_7_0	0x14
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE10_7_0	0x15
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE9_7_0		0x16
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE8_7_0		0x17
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE7_7_0		0x18
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE6_7_0		0x19
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE5_7_0		0x1A
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE4_7_0		0x1B
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE3_7_0		0x1C
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE2_7_0		0x1D
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE1_7_0		0x1E
#define PROP_MODEM_CHFLT_RX2_CHFLT_COE0_7_0		0x1F
#define PROP_MODEM_CHFLT_RX2_CHFLT_COEM0		0x20
#define PROP_MODEM_CHFLT_RX2_CHFLT_COEM1		0x21
#define PROP_MODEM_CHFLT_RX2_CHFLT_COEM2		0x22
#define PROP_MODEM_CHFLT_RX2_CHFLT_COEM3		0x23

#define PROP_PA_GROUP		      		            0x22
#define PROP_PA_MODE							    0x00
#define PROP_PA_PWR_LVL							    0x01
#define PROP_PA_BIAS_CLKDUTY		        		0x02
#define PROP_PA_TC							        0x03
#define PROP_PA_RAMP_EX					          	0x04
#define PROP_PA_RAMP_DOWN_DELAY			      		0x05

#define PROP_MATCH_GROUP				          		0x30
#define PROP_MATCH_VALUE_1			        			0x00
#define PROP_MATCH_MASK_1				          		0x01
#define PROP_MATCH_CTRL_1				           		0x02
#define PROP_MATCH_VALUE_2			        			0x03
#define PROP_MATCH_MASK_2			          			0x04
#define PROP_MATCH_CTRL_2			          			0x05
#define PROP_MATCH_VALUE_3			        			0x06
#define PROP_MATCH_MASK_3				          		0x07
#define PROP_MATCH_CTRL_3				           		0x08
#define PROP_MATCH_VALUE_4			        			0x09
#define PROP_MATCH_MASK_4				          		0x0A
#define PROP_MATCH_CTRL_4				          		0x0B

#define PROP_FREQ_CONTROL_GROUP			      		0x40
#define PROP_FREQ_CONTROL_INTE			      		0x00
#define PROP_FREQ_CONTROL_FRAC_2		      		0x01
#define PROP_FREQ_CONTROL_FRAC_1		      		0x02
#define PROP_FREQ_CONTROL_FRAC_0		      		0x03
#define PROP_FREQ_CONTROL_CHANNEL_STEP_SIZE_1	    0x04
#define PROP_FREQ_CONTROL_CHANNEL_STEP_SIZE_0		0x05
#define PROP_FREQ_CONTROL_W_SIZE			      	0x06
#define PROP_FREQ_CONTROL_VCOCNT_RX_ADJ	  			0x07

#define PROP_RX_HOP_GROUP						    0x50
#define PROP_RX_HOP_CONTROL					        0x00
#define PROP_RX_HOP_TABLE_SIZE				        0x01
#define PROP_RX_HOP_TABLE_ENTRY_0				    0x02
#define PROP_RX_HOP_TABLE_ENTRY_1		      		0x03
#define PROP_RX_HOP_TABLE_ENTRY_2			      	0x04
#define PROP_RX_HOP_TABLE_ENTRY_3			      	0x05
#define PROP_RX_HOP_TABLE_ENTRY_4			      	0x06
#define PROP_RX_HOP_TABLE_ENTRY_5			      	0x07
#define PROP_RX_HOP_TABLE_ENTRY_6		      		0x08
#define PROP_RX_HOP_TABLE_ENTRY_7		      		0x09
#define PROP_RX_HOP_TABLE_ENTRY_8			      	0x0A
#define PROP_RX_HOP_TABLE_ENTRY_9			      	0x0B
#define PROP_RX_HOP_TABLE_ENTRY_10     				0x0C
#define PROP_RX_HOP_TABLE_ENTRY_11	     			0x0D
#define PROP_RX_HOP_TABLE_ENTRY_12	      		    0x0E
#define PROP_RX_HOP_TABLE_ENTRY_13	  		   	    0x0F
#define PROP_RX_HOP_TABLE_ENTRY_14	     			0x10
#define PROP_RX_HOP_TABLE_ENTRY_15	    			0x11
#define PROP_RX_HOP_TABLE_ENTRY_16		    		0x12
#define PROP_RX_HOP_TABLE_ENTRY_17	    			0x13
#define PROP_RX_HOP_TABLE_ENTRY_18		    		0x14
#define PROP_RX_HOP_TABLE_ENTRY_19			    	0x15
#define PROP_RX_HOP_TABLE_ENTRY_20			        0x16
#define PROP_RX_HOP_TABLE_ENTRY_21    				0x17
#define PROP_RX_HOP_TABLE_ENTRY_22    				0x18
#define PROP_RX_HOP_TABLE_ENTRY_23    				0x19
#define PROP_RX_HOP_TABLE_ENTRY_24    				0x1A
#define PROP_RX_HOP_TABLE_ENTRY_25	    			0x1B
#define PROP_RX_HOP_TABLE_ENTRY_26    				0x1C
#define PROP_RX_HOP_TABLE_ENTRY_27	    			0x1D
#define PROP_RX_HOP_TABLE_ENTRY_28	    			0x1E
#define PROP_RX_HOP_TABLE_ENTRY_29	    			0x1F
#define PROP_RX_HOP_TABLE_ENTRY_30		    		0x20
#define PROP_RX_HOP_TABLE_ENTRY_31		    		0x21
#define PROP_RX_HOP_TABLE_ENTRY_32		     		0x22
#define PROP_RX_HOP_TABLE_ENTRY_33		    		0x23
#define PROP_RX_HOP_TABLE_ENTRY_34		    		0x24
#define PROP_RX_HOP_TABLE_ENTRY_35		    		0x25
#define PROP_RX_HOP_TABLE_ENTRY_36		    		0x26
#define PROP_RX_HOP_TABLE_ENTRY_37		    		0x27
#define PROP_RX_HOP_TABLE_ENTRY_38		    		0x28
#define PROP_RX_HOP_TABLE_ENTRY_39		    		0x29
#define PROP_RX_HOP_TABLE_ENTRY_40		     		0x2A
#define PROP_RX_HOP_TABLE_ENTRY_41		    		0x2B
#define PROP_RX_HOP_TABLE_ENTRY_42		    		0x2C
#define PROP_RX_HOP_TABLE_ENTRY_43			     	0x2D
#define PROP_RX_HOP_TABLE_ENTRY_44    				0x2E
#define PROP_RX_HOP_TABLE_ENTRY_45    				0x2F
#define PROP_RX_HOP_TABLE_ENTRY_46     				0x30
#define PROP_RX_HOP_TABLE_ENTRY_47		    		0x31
#define PROP_RX_HOP_TABLE_ENTRY_48			    	0x32
#define PROP_RX_HOP_TABLE_ENTRY_49			     	0x33
#define PROP_RX_HOP_TABLE_ENTRY_50		    		0x34
#define PROP_RX_HOP_TABLE_ENTRY_51		    		0x35
#define PROP_RX_HOP_TABLE_ENTRY_52		    		0x36
#define PROP_RX_HOP_TABLE_ENTRY_53		    		0x37
#define PROP_RX_HOP_TABLE_ENTRY_54		    		0x38
#define PROP_RX_HOP_TABLE_ENTRY_55			    	0x39
#define PROP_RX_HOP_TABLE_ENTRY_56			    	0x3A
#define PROP_RX_HOP_TABLE_ENTRY_57    				0x3B
#define PROP_RX_HOP_TABLE_ENTRY_58	    			0x3C
#define PROP_RX_HOP_TABLE_ENTRY_59		    		0x3D
#define PROP_RX_HOP_TABLE_ENTRY_60			    	0x3E
#define PROP_RX_HOP_TABLE_ENTRY_61  	  			0x3F
#define PROP_RX_HOP_TABLE_ENTRY_62	  	  		    0x40
#define PROP_RX_HOP_TABLE_ENTRY_63				    0x41


//Fast response register commands
#define CMD_FAST_RESPONSE_REG_A			0x50
#define CMD_FAST_RESPONSE_REG_B			0x51
#define CMD_FAST_RESPONSE_REG_C			0x53
#define CMD_FAST_RESPONSE_REG_D			0x57
//-----------------------------------------------------------------------------
// Header File PreProcessor Directive
//-----------------------------------------------------------------------------
#endif                                 // #define SI446X_B1_DEFS_H

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
