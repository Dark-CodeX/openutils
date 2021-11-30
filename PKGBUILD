pkgname="sstring"
pkgver="49.3.0"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "7cdd82eed3f16962a352c6f99fbe8fc6548a739778a7ce828a1a65bab9510e26eb78afb97e51064b7bf926c6c6ed3dab53ef89b9bce36d6734306296c5465fd0"
  "fbedd3ff794a362c166695bfa5ae62f8cd39bab9ca306c56c798414d3ceedcfeeb9428c24a00d4e614bffb4953b8ed81aef7c97d911ee47d499d54ea3658490f"
  "3426d5fcf5b6ac004be912ff9be43283db2fcac463458c2a76c2e72ce5f16d28c345dbc0d56577e206254b46aad3ff63d741e6d61ba09e579f88d142e5f6f54d"
  "b538c753c3335840cd3ffe9b2488c3a8436787251640e26086fdb91d872111100367ed756f2ae7a7e0cd68d1581dd2de226ea01e8e96c7165bddafc5d1dfcdb9"
  "13b59622d299412966a9e008458b9c38c7c07e0694022aea1f884a620c2dd18eb3b8477948fad848f5d5e8cca0967be109b338560255fef58d831e487d09ee8a")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
