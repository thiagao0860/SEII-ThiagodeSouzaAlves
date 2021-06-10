1 - Resposta 

- As seis dicas mencionadas pelo autor durante o video são:

1. Disable SSH Password Login
O uso direto de senhas repassadas de forma simples diretamente aos servidor vem se tornando uma prática amplamente desencorajada, tanto porque já existem maneiras muito mais seguras de realizar esta autenticação quanto porque quando esta opção no contexto do protocolo SSH automaticamente ativa a comunicação por clear text o que é altamente não recomendado do ponto de vista de segurança.
2. Disable Direct root SSH Login
É mais vantajoso utilizar, assim como utilizado geralmente em distros do Linux para End Users, não utilizar o acesso de root diretamente, e ao inves disso configurar um usuário com acesso padrão e depois acessá-lo com contexto sudo (se possível utilize-de da configuração de alias) pois assim teremos maior controle dos acessos repassados a possíveis atacantes, além de inserir uma camada extra de proteção até para possíveiserros ou confusões do próprio programador. 
3. Change Default SSH Port
Trocar a porta padrão de comunicação é uma atitude recomendada em vários ambientes da comunicação via internet pois ela diminui significativamente os riscos de ataques mais simples (mais igualmente perigosos) feitos por atacantes que não conhecem qual a porta utilizada e buscam prefencialmente a porta padrão. 
4. Disable IPv6 for SSH
Apesar de o IPv6 ser uma tecnologia em crescimento e com grandes chances de se tornar uma necessidade, do ponto de vista da segurança ele representa um grupo e funcionalidades muito maior do que o IPv4, porém na maior parte das vezes essas funcionalidades não estão sendo utilizadas pelo desenvolvedor do sistema, servindo apenas para abrir o leque de ferramentas de possíveis atacantes
5. Setup a Basic Firewall
O autor chama atenção especialmente para uma escolha consiente de qual o sistema de Firewall será utilizado pois muitas das vezes desenvolvedores utilizam firewalls altamente potentes de em ambientes q a sua função será simplesmente fechar as portas inutilizadas, gerando gastos desnecessários, ou pior ainda gerando uma  falsa sensação de segurança
6. Unattended Server Auto Upgrade
Auto Upgrade é uma funcionalidade essencial em sistemas de usuário final, pois permite manter o user protegido de novas tipos de ataques, virús e entre outros; porém essa realidade não se estende aos servidores, isso porque muitas vezes os serviços programados não conseguem se adaptar as mudanças tão facilmete quanto os usuários finais e dependem de características específicas dos sistemas utilizados ficando a mercê de bugs e vulnerabilidades quando estas atualizações acontecem.