### 1 - Resposta 

- As seis dicas mencionadas pelo autor durante o video são:

1. Disable SSH Password Login:
O uso direto de senhas repassadas de forma simples diretamente aos servidor vem se tornando uma prática amplamente desencorajada, tanto porque já existem maneiras muito mais seguras de realizar esta autenticação quanto porque quando esta opção no contexto do protocolo SSH automaticamente ativa a comunicação por clear text o que é altamente não recomendado do ponto de vista de segurança.
2. Disable Direct root SSH Login:
É mais vantajoso utilizar, assim como utilizado geralmente em distros do Linux para End Users, não utilizar o acesso de root diretamente, e ao inves disso configurar um usuário com acesso padrão e depois acessá-lo com contexto sudo (se possível utilize-de da configuração de alias) pois assim teremos maior controle dos acessos repassados a possíveis atacantes, além de inserir uma camada extra de proteção até para possíveiserros ou confusões do próprio programador. 
3. Change Default SSH Port:
Trocar a porta padrão de comunicação é uma atitude recomendada em vários ambientes da comunicação via internet pois ela diminui significativamente os riscos de ataques mais simples (mais igualmente perigosos) feitos por atacantes que não conhecem qual a porta utilizada e buscam prefencialmente a porta padrão. 
4. Disable IPv6 for SSH:
Apesar de o IPv6 ser uma tecnologia em crescimento e com grandes chances de se tornar uma necessidade, do ponto de vista da segurança ele representa um grupo e funcionalidades muito maior do que o IPv4, porém na maior parte das vezes essas funcionalidades não estão sendo utilizadas pelo desenvolvedor do sistema, servindo apenas para abrir o leque de ferramentas de possíveis atacantes
5.Setup a Basic Firewall:
O autor chama atenção especialmente para uma escolha consiente de qual o sistema de Firewall será utilizado pois muitas das vezes desenvolvedores utilizam firewalls altamente potentes de em ambientes q a sua função será simplesmente fechar as portas inutilizadas, gerando gastos desnecessários, ou pior ainda gerando uma  falsa sensação de segurança:
6. Unattended Server Auto Upgrade
Auto Upgrade é uma funcionalidade essencial em sistemas de usuário final, pois permite manter o user protegido de novas tipos de ataques, virús e entre outros; porém essa realidade não se estende aos servidores, isso porque muitas vezes os serviços programados não conseguem se adaptar as mudanças tão facilmete quanto os usuários finais e dependem de características específicas dos sistemas utilizados ficando a mercê de bugs e vulnerabilidades quando estas atualizações acontecem.

### 2 - Resposta 

- a) A melhor maneira de salvar os dados de forma a proteger tanto a informação do usuário quanto a segurança  do sistema seria passar sua senha por uma engine de IDs universais, exemplos clássicos destes modelos são: UUID e GUID.

- b) Criptográfia de chave simétrica é caracterizada pelo uso de uma função que encripta (ou decripta) os dados em uma nova sequência encriptada (ou decripta) utilizando uma mesma chave, embora os tipos de implementação possam ser os mais variados podendo gerar resultados de mesmo tamanho, tamanho variados, resultados que se repetem de acordo com a entrada e entre outros. podendo ser visto de forma simplificada como:

tome um modelo M de entrada E e saida S logo: S = M(E) <=> E = M(S)

- c) De forma resumida podemos dizer que um sistema está preocupado com a transmição de uma mensagem isto é que os dados possam ser transmitidos de forma segura entre dois interlocutores, sem serem lidos por interceptadores intermediários, isso gera uma necessidade primária aos sistemas de criptográfia que os dados vistos pelos interlocutores originais sejam exatamente iguais. Por outro lado os sistemas de HASH estão preocupados com a geraçãod de uma impressão digital do arquivo, desta forma os dados gerados por um HASH embora possam ser comparados (isso não garante a igualdade perfeita entre dois arquivos aleatórios embora em ambientes especificos seja muito improvável que o arquivos não seja o mesmo), não é possivel reconstruir um arquivo base a partir de ser HASH.

### 3 - Resposta 

- A) Uma das principais características do bitcoin é seu sistema distribuido (que não depende de um certificador principal), a base por trás deste sistema é o uso de um sistema específico (e custoso) de criação de HASHs os quais são guardados na famigerada Blockchain, a grande sacada por tras do Bitcoin é permitir que estas operações altamente custosas de geração de HASH possas ser feitas por qualquer e ofereçer grandes quantias pelo resultado assim alcançando a grande popularidade da moeda.

- B) O HTTPS é uma extensão segura do HTTP de forma que os sites configuraram um certificado SSL/TLS para estabelecer uma comunicação segura com o servidor. SSL significa Secure Sockets Layer, um tipo de segurança digital que permite a comunicação criptografada entre um site e um navegador. Atualmente a tecnologia se encontra depreciada e está sendo completamente substituída pelo TLS. TLS é uma sigla que representa Transport Layer Security e certifica a proteção de dados de maneira semelhante ao SSL. 

- C) O Certificado Digital é uma maneira simples de garantir o gerador de determinado dado em um modelo altamente distribuido como a internet, geralmente esses sitemas se utilizam de uma caracteristica importante dos sistemas de chave dupla ou assimétricos quando se aplica o modelo de forma "inversa", ou seja, o gerador da mensagem utiliza a chave privada todos os receptores poderão utilizar a chave pública como uma espécie de assinatura única do arquivo. A Infraestrutura de Chaves Públicas Brasileira – ICP-Brasil é uma cadeia hierárquica de confiança que viabiliza a emissão de certificados digitais para identificação virtual do cidadão. Observa-se que o modelo adotado pelo Brasil foi o de certificação com raiz única, sendo que o ITI, além de desempenhar o papel de Autoridade Certificadora Raiz – AC-Raiz, também tem o papel de credenciar e descredenciar os demais participantes da cadeia, supervisionar e fazer auditoria dos processos.