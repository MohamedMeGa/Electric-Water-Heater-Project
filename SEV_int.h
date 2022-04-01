/**************************************************/
/*   AUTHOR      : MOHAMED	MEGA	              */
/*   Description : SEVEN SEGMENT DRIVER           */
/*   DATE        : 30 SET 2021                    */
/*   VERSION     : V01                            */
/**************************************************/

#ifndef	SEV_INT_H
#define	SEV_INT_H

/**		TYPE OF 7 SEG	RIGHT OR LEFT				*/
#define	SEV_SEG_LEFT	1
#define	SEV_SEG_RIGHT	0	


/***************************************************/
/* Description :  PROTOTYPE DECLARTION 		   	   */



/* Description :  function to set 7 segment type and value			*/

void	SEV_VoidSET7SegmentValue(u8	COPY_U8SEVSEGMENTNUM, u8	COPY_U8SEVSEGMENTVALUE);


#endif