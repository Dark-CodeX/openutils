pkgname="openutils-sstring"
pkgver="1.6.4"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
  "9e1616d09f07424976ba14dc35c1de5a810d38c546df65ba473d57e493e5516b7e5eb731888b1eb01e2aa7f2e785feeae875fb2bccab8125647033ef6b61f796"
  "5edc8e4b70c295675c9d48eff4e33c76af506c0d1bcd8b86251d6e9cdacdb83028ce75eebe9440ded79839ba32ee0d5f67a8299c50f1ca5a8ccd5253f8b835fa"
  "a3aeb4490cdfba9712f9345204c429c8be7ebd35cbc37a762c709931a76320fb64cc8a8994d08e533e642fafc5741753992f8219f72dee0aa34baa4ec25256d9"
  "684891f0c146eb600881456b65f7c1f8379977a6796ffe79e3f29271cfb23413c7dbfb337b18cd065448e79d9613e0c094483f9c823ff7aeaecb62f0cb75ea35"
  "49ab33b13481c716c9b24731848f8168558029d152e8dab2c40cb2aa21dbff3e4eff32e67dc2e006bf084e3c4a0370931a4da583caa9011aa0c910a34f73d6bf")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
  echo "Done!"
}
