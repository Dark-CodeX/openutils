pkgname="sstring"
pkgver="16.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("90bcebda59275724faa21fcc0f5767c027b7af7857faed867b0e21793f1b67851dd5b4cde7994489d09d5ec5ea3fe08c2d2a3439d6a9bfbb9ece4e3f92898a9d" "1eeae59fb6722783113bfdb36e54860fa619c5e1a7a642273e4e08c1e1250cad96fcfef5375ec84fc57a13814c3afa4d10722403b3529e8085a42d0834280a84" "3be47413eea883894e8ca7db56b62aca98df792d91afb910c37ef45375390c0dab4e79d3526122d9d3364b084f2a67111ff3961c4874d88e73bdc9119b1a3a25")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
