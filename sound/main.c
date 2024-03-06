#include <creativision.h>
void main (void)
{
  psg_outb (0x80); // Latch frequency
  psg_outb (0x07); // Frequency byte 2
  psg_outb (0x90); // Channel 0 full volume
  psg_delay (100);
  psg_silence ();
}