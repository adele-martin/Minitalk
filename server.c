#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf/include/ft_printf.h"


#include "minitalk.h"

void ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char character = 0;
	static int	bit_count = 0;
	static pid_t	client_pid = 0;

 	(void)context;
 	if (client_pid != info->si_pid)
 	{
  		bit_count = 0;
  		character = 0;
 	}
 	client_pid = info->si_pid;
 	character = character << 1;
 	if (signum == SIGUSR1)
  		character = character | 1;
 	bit_count++;
 	if (bit_count == 8)
 	{
  		write(1, &character, 1);
  		bit_count = 0;
  		character = 0;
	 }
 	kill(client_pid, SIGUSR2);
}

int	main()
{
	struct sigaction sa;

 	ft_printf("Server PID: %d\n", getpid());
 	sa.sa_sigaction = &ft_handle_signal;
 	sa.sa_flags = SA_SIGINFO;
 	sigaction(SIGUSR1, &sa, NULL);
 	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
			pause();
	}
	return (0);
}
